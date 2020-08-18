#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);


        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }

            break;
        }
        printf("%i\n", min);
        // Eliminate anyone with minimum number of votes

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        //If the two strings are the same, the strcmp function gives the value of 0
        if (strcmp(name, candidates[i].name) == 0)
        {
            //If the strings are the same, assigns the two dimensional preferences array
            preferences[voter][rank] = i;
            return true;
        }
    }


    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{

    for (int i = 0; i < voter_count; i++)
    {

        for (int j = 0; j < candidate_count; j++)
        {
            //Uptade serves as a single variable to assign to the two dimensional preferences array
            int pref = preferences[i][j];
            //If the j of i (candidates of voters) is not eliminated, uptade the vote to 1 +
            if (candidates[pref].eliminated == false)
            {
                candidates[pref].votes++;
                //This break reboot the cicle
                break;
            }
        }

    }

}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int votes = 0;
    bool winner = false;
    //Here the majority is the voter count divided by two. Used the round function to have only an integer
    int majority = round(voter_count / 2);
    //Iterate over the candidates
    for (int i = 0; i < candidate_count; i++)
    {
        //If the votes of the candidate are greater than majority, print he's the winner, and return true
        if (candidates[i].votes > majority)
        {
            winner = true;
            printf("The winner is %s\n", candidates[i].name);
            return winner;
        }
        else
            //Else, return false
        {
            winner = false;
        }
    }
    return winner;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = voter_count;
    //Selection Sort
    for (int i = 0; i < candidate_count; i++)
    {
        //Takes the only the minimum value with the eliminated value of false
        if (candidates[i].votes < min && candidates[i].eliminated == false)
        {
            //Assign the minimun value to min, so to assign again it must be smaller
            min = candidates[i].votes;
        }

    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    bool tie = false;
    int counter1 = 0;
    int counter2 = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            counter1++;
            if (candidates[i].votes == min)
            {
                counter2++;
            }
        }

    }
    if (counter1 == counter2)
    {
        tie = true;
    }

    return tie;
}
// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}

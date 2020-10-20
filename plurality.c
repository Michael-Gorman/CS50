#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        // if name == candidate name in list
        if (strcmp(candidates[i].name, name) == 0)
        {
            //add 1 to that candidates vote count
            candidates[i].votes++;
            return true;
        }
    }
    //if that name doesnt match any candidate, return false
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    //Initialize max votes counter:
    int max_votes = 0;

    //Find highest number of votes

    //Iterate through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        //if candidate vote count is larger than max_votes
        if (candidates[i].votes > max_votes)
        {
            //max_votes is now equal to the candidate vote count
            max_votes = candidates[i].votes;
        }
    }

    //Print winners
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }


    return;
}

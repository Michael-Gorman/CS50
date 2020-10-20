#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

string get_input(void);
int letter_counter(string s);
int word_counter(string s);
int sentence_counter(string s);
float index_calc(int letter_c, float word_c, int sentence_c);

int main(void)
{
    //Get and return input Text from user:
    string t = get_input();

    //Take input and return letter count from text:
    int l = letter_counter(t);
    //printf("l = %i\n", l);

    //Take input and return number of words from text:
    float w = word_counter(t);
    //printf("w = %f\n", w);

    //Take input and return Sentence count from text:
    int s = sentence_counter(t);
    //printf("s = %i\n", s);

    //Calculate and return the reading grade usig the Coleman-Liau index formula:
    // index = 0.0588 * L - 0.296 * S - 15.8
    float index = index_calc(l, w, s);

    //Round the index to an int
    int grade = roundf(index);
    //printf("Grade = %i\n", grade);


    //print the reading Grade of the text:
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    if (grade < 16 && grade >= 1)
    {
        printf("Grade %i\n", grade);
    }
    // printf("%s\n", t);
}



////////////////////////////////////////////////////////////////////
//Imput method:
string get_input(void)
{
    string text = get_string("Text:  ");
    return text;
}

////////////////////////////////////////////////////////////////////
//Take input and return letter count.
int letter_counter(string s)
{
    //letter counter initailize:
    int let_count = 0;

    // increment through Array "s" until "n", (where n is the string length) (treating the string as an array)
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //if position "i" in Array s is between "a" AND "z" (lower case)  OR    between  "A" AND "Z"  (upper case)
        if ((s[i] >= 'a' && s[i] <= 'z')  || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            //Increment letter counter
            let_count++;

            //printf to test if the if statement works.
            //printf("%c", s[i]);
        }
    }
    //printf("\n");
    //printf conter to test
    //printf("Letter Count: %i\n", let_count);
    return let_count;
}

/////////////////////////////////////////////////////////////////////
//Take input and return word count.
int word_counter(string s)
{
    //word counter initailisation: (starting at one as the final word wont have a space after it.)
    int word_count = 1;

    // increment through Array "s" until "n", (where n is the string length) (treating the string as an array)
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //if postion "i" is equal to a space " " then we can add another word to the count
        if (s[i] == ' ')
        {
            //Increment letter counter
            word_count++;
        }
    }
    //printf("Word Count: %i\n", word_count);
    return word_count;
}

///////////////////////////////////////////////////////////////////
//Take input and return Sentence count.
int sentence_counter(string s)
{
    //Sentence counter initailisation: (starting at one as the final word wont have a space after it.)
    int sentence_count = 0;

    // increment through Array "s" until "n", (where n is the string length) (treating the string as an array)
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //if postion "i" is equal to a space " " then we can add another word to the count
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            //Increment letter counter
            sentence_count++;
        }
    }
    //printf("Sentence Count: %i\n", sentence_count);
    return sentence_count;
}

///////////////////////////////////////////////////////////////////
//Take letter count, word count, and sentence count and use Colman-Liau formaula to calculate reading grade
float index_calc(int letter_c, float word_c, int sentence_c)
{
    //printf("word_c = %f\n", word_c);
    //Calculate ratio of words in text to 100 words:
    float word_r = 100 / word_c;
    //printf("word_r = %f\n", word_r);

    //Calculate average letters per 100 words:
    float L = letter_c * word_r;
    //printf("L = %f\n",L);


    //Calculate average sentences per 100 words:
    float S = sentence_c * word_r;
    //printf("S = %f\n",S);


    //Colman-Liau formula using calculated values:
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    //printf("index: %.2f\n", index);
    return index;
}

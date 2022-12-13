#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int get_index(string t);

int main(void)
{
    string s = get_string("Text: ");
    int index = get_index(s);
    if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(index >= 16)
    {
        printf("Grade 16+\n");
    }
    else{
        printf("Grade %d\n", index);
    }
    return 0;
}

int get_index(string t)
{
    int letter = 0, word = 0, sentence = 0;
    for (int i = 0; i < strlen(t); i++)
    {
        // Since we know that a string is an array of character/s
        char ch = t[i];
        if(isalpha(ch))
        {
            letter++;
        }

        if(isspace(ch))
        {
        //Space is used to differentiate one word from another, thus we use space to show the increment
            word++;
        }

        if(ch == '!'|| ch =='.'|| ch =='?')
        {
            sentence++;
        }
    }
    word++;

    //Coleman-Liau index
    float L = (letter*100.0f)/ word;
    float S = (sentence*100.0f)/ word;
    return  round((0.0588 * L) -(0.296 * S) - 15.8);
}
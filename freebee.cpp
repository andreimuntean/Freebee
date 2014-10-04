/*
You have the word FREEBEE. How many words can you form by moving the letters around?
How many words can you form that start and end in E? How many words can you have that
contain the sequence "EEEE"?
E = 0
F = 1
R = 2
B = 30
*/

#include <iostream>
#define length 7

using namespace std;

int values[5040][length], valuesCount;
int word[length] = { 1, 2, 0, 0, 3, 0, 0 };
int answers[3];

void question1(int word[])
{
    ++answers[0];
}

void question2(int word[])
{
    if (word[0] == 0 && word[length - 1] == 0)
    {
        ++answers[1];
    }
}

void question3(int word[])
{
    int count = 0;

    for (int i = 0; i < length; ++i)
    {
        if (word[i] == 0)
        {
            ++count;

            if (count == 4)
            {
                ++answers[2];

                return;
            }
        }
        else 
        {
            count = 0;
        }
    }
}

void answerQuestions()
{
    for (int i = 0; i < valuesCount; ++i)
    {
        question1(values[i]);
        question2(values[i]);
        question3(values[i]);
    }
}

void showAnswers()
{
    for (int i = 0; i < 3; ++i)
    {
        cout << "Answer to Q" << i + 1 << ": " << answers[i] << endl;
    }
}

bool equals(int word1[], int word2[])
{
    for (int i = 0; i < length; ++i)
    {
        if (word1[i] != word2[i])
        {
            return false;
        }
    }
    
    return true;
}

bool isUnique(int word[])
{
    for (int i = 0; i < valuesCount; ++i)
    {
        if (equals(word, values[i]))
        {
            return false;
        }
    }

    return true;
}

void store(int word[])
{
    if (isUnique(word))
    {
     	for (int i = 0; i < length; ++i)
        {
            values[valuesCount][i] = word[i];
        }

	    ++valuesCount;
    }
}

void swap(int word[], int i, int j)
{
    int temp = word[i];
    word[i] = word[j];
    word[j] = temp;
}

void generatePermutations(int word[], int start)
{
    if (start == length)
    {
        store(word);
    }
    else 
    {
        for (int i = start; i < length; ++i)
        {
            swap(word, start, i);
            generatePermutations(word, start + 1);
            swap(word, start, i);
        }
    }
}

int main()
{
    generatePermutations(word, 0);
    answerQuestions();
    showAnswers();

    return 0;
}

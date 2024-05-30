#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printN(int size, vector<string> &output, int offset)
{
    for (int i = 0; i < size; ++i)
    {
        output[i][offset] = '*';
        output[i][offset + size - 1] = '*';
        output[i][offset + i] = '*';
    }
}

void printO(int size, vector<string> &output, int offset)
{
    for (int i = 0; i < size; ++i)
    {
        output[i][offset] = '*';
        output[i][offset + size - 1] = '*';
        if (i == 0 || i == size - 1)
        {
            for (int j = 0; j < size; ++j)
            {
                output[i][offset + j] = '*';
            }
        }
    }
}

void printK(int size, vector<string> &output, int offset)
{
    int mid = size / 2;
    for (int i = 0; i < size; ++i)
    {
        output[i][offset] = '*';
        if (i < mid)
        {
            output[i][offset + (mid - i)] = '*';
        }
        else if (i > mid)
        {
            output[i][offset + (i - mid)] = '*';
        }
    }
}

void printI(int size, vector<string> &output, int offset)
{
    for (int i = 0; i < size; ++i)
    {
        output[i][offset + size / 2] = '*';
        if (i == 0 || i == size - 1)
        {
            for (int j = 0; j < size; ++j)
            {
                output[i][offset + j] = '*';
            }
        }
    }
}

void printA(int size, vector<string> &output, int offset)
{
    int mid = size / 2;
    for (int i = 0; i < size; ++i)
    {
        output[i][offset] = '*';
        output[i][offset + size - 1] = '*';
        if (i == mid)
        {
            for (int j = 0; j < size; ++j)
            {
                output[i][offset + j] = '*';
            }
        }
    }
    for (int i = 0; i <= mid; ++i)
    {
        output[i][offset + i] = '*';
        output[i][offset + size - 1 - i] = '*';
    }
}

void printWord(const string &word, int size)
{
    vector<string> output(size, string((size + 2) * word.length() - 1, ' '));

    for (int i = 0; i < word.length(); ++i)
    {
        int offset = i * (size + 2);
        switch (word[i])
        {
        case 'N':
            printN(size, output, offset);
            break;
        case 'O':
            printO(size, output, offset);
            break;
        case 'K':
            printK(size, output, offset);
            break;
        case 'I':
            printI(size, output, offset);
            break;
        case 'A':
            printA(size, output, offset);
            break;
        }
    }

    for (const string &line : output)
    {
        cout << line << endl;
    }
}

int main()
{
    string word = "NOKIA";
    int size = 5; // You can adjust the size as needed
    cout<<"Bine ati venit la Liga AC LABS!"<<endl;
    printWord(word, size);
    cout<<"Multumim pentru participare!"<<endl;
     return 0;
}

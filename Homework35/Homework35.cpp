#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

char cript(char c, int k)
{
    if (c >= 65 && c <= 90)
    {
        c = c - 65;
        c = (c + k) % 26;
        if (c < 0)
        {
            c = 26 - c;
        }
        c = c + 65;
    }
    else if (c >= 97 && c <= 122)
    {
        c = c - 97;
        c = (c + k) % 26;
        if (c < 0)
        {
            c = 26 - c;
        }
        c = c + 97;
    }
    return c;
}
int main()
{
    const char* pathOut = "Source2.txt";
    const char* pathIn = "Destination2.txt";
    FILE* fileOut, * fileIn;

    int k = 0;
    cout << "Шифрование с использованием ключа: ";
    cin >> k;

    if (fopen_s(&fileOut, pathOut, "r") != NULL)
    {
        cout << "The file cannot be opened";
    }
    else if (fopen_s(&fileIn, pathIn, "w") != NULL)
    {
        cout << "The file cannot be opened";
    }
    else
    {
        char c[1];
        while (fscanf(fileOut, "%c", c) == 1)
        {
            c[0] = cript(c[0], k);
            fprintf(fileIn, "%c", c[0]);
        }
        fclose(fileOut);
        fclose(fileIn);
    }
}
//
//  main.cpp
//  CPP-PRG-10-06-Vowels-and-Consonants
//
//  Created by Keith Smith on 11/2/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a function that accepts a pointer to a C-string as its argument. The function
//  should count the number of vowels appearing in the string and return that number.
//  Write another function that accepts a pointer to a C-string as its argument. This
//  function should count the number of consonants appearing in the string and return that
//  number.
//
//  Demonstrate these two functions in a program that performs the following steps:
//
//      1. The user is asked to enter a string.
//      2. The program displays the following menu:
//          A) Count the number of vowels in the string
//          B) Count the number of consonants in the string
//          C) Count both the vowels and consonants in the string
//          D) Enter another string
//          E) Exit the program
//      3. The program performs the operation selected by the user and repeats until the user
//         selects E to exit the program.
//
//

#include <iostream>
#include <cstring>

using namespace std;

const int INT_ARR_SIZE = 999;

char *getStringAsCharArray();
int *truncateCharArrayIndex(char *);
char *truncateCharArray(char *, int *);
void countLetterTypes(char *, int *, int *, int *);

int main()
{
    char *chrArrayOriginal = nullptr;
    char *chrArrayResized = nullptr;
    
    int *intIndexResized = nullptr;
    int *intCounterVowels = nullptr;
    int *intCounterConsonants = nullptr;
    
    intCounterVowels = new int;
    *intCounterVowels = 0;
    
    intCounterConsonants = new int;
    *intCounterConsonants = 0;
    
    chrArrayOriginal = getStringAsCharArray();
    
    intIndexResized = truncateCharArrayIndex(chrArrayOriginal);
    chrArrayResized = truncateCharArray(chrArrayOriginal, intIndexResized);
    
    countLetterTypes(chrArrayResized, intIndexResized, intCounterVowels, intCounterConsonants);
    
    cout << "Vowels: " << *intCounterVowels << endl;
    cout << "Consonants: " << *intCounterConsonants << endl;
    
    return 0;
}

char *getStringAsCharArray()
{
    char *chrArr;
    
    chrArr = new char[INT_ARR_SIZE];
    
    cout << "Please enter a string:\n";
    cin.getline(chrArr, INT_ARR_SIZE);
    
    return chrArr;
}

int *truncateCharArrayIndex(char *chrArr)
{
    int *intIndex = nullptr;
    intIndex = new int;
    *intIndex = 0;
    
    for (int i = 0 ; i < INT_ARR_SIZE ; i++)
    {
        *intIndex += 1;
        
        if (chrArr[i] == '\0')
        {
            break;
        }
    }
    
    return intIndex;
}

char *truncateCharArray(char *chrArr, int *intIndex)
{
    char *chrArrNew = nullptr;
    chrArrNew = new char[*intIndex];
    
    for (int i = 0 ; i < *intIndex ; i++)
    {
        chrArrNew[i] = chrArr[i];
    }
    
    return chrArrNew;
}

void countLetterTypes(char *chrArr, int *intIndex, int *intVowels, int *intConsonants)
{
    for (int i = 0 ; i < *intIndex ; i++)
    {
        if (chrArr[i] == 'a' || chrArr[i] == 'e' || chrArr[i] == 'i' || chrArr[i] == 'o' || chrArr[i] == 'u')
        {
            *intVowels += 1;
        }
        else if (chrArr[i] != ' ' && chrArr[i] != '\0')
        {
            *intConsonants += 1;
        }
        else if (chrArr[i] == ' ' || chrArr[i] == '\0')
        {
            
        }
        else
        {
            cout << "ERROR DETERMINING CHARACTER TYPE\n";
            exit(1);
        }
    }
}

/*
 * Name: Robert Arnold 
 * Date Submitted: 03/02/2022
 * Lab Section: 003
 * Assignment Name: Lab 5 - Spell Checker Using a HAsh Table Starter Code
 */

#include "stringset.h"
using namespace std;

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

void Stringset::insert(string word)
{
    if(!find(word))
    {
        int pos;
        string tempWord;
        hash<string> hashStr;
        
        if(num_elems >= size)
        {
            size = size * 2;
            vector<list<string>> tempTable(size);
            
            for(int i = 0; i < size / 2; i++)
            {
                for(list<string>::const_iterator ap = table[i].begin(); ap != 
                    table[i].end(); ++ap)
                    {
                        tempWord = *ap;
                        pos = hashStr(tempWord) % size;
                        tempTable[pos].push_back(tempWord);
                        table[i].remove(word);
                    }
            }
            table = tempTable;
        }
        pos = hashStr(word) % size;
        table[pos].push_back(word);
        num_elems++;
    }
}

bool Stringset::find(string word) const
{
    hash<string> hashStr;
    int pos = hashStr(word) % size;

    for(list<string>::const_iterator ap = table[pos].begin(); ap != table[pos].end(); ++ap)
    {
        if(*ap == word)
        {
            return true;
        }
    }
    return false;
}

void Stringset::remove(string word)
{
    if(find(word))
    {
        hash<string> hashStr; 
        int pos = hashStr(word) % size;
        table[pos].remove(word);
        num_elems--;
    }
}
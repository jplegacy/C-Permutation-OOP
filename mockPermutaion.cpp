#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include "mockPermutation.h"

using namespace std;

/**
 * Vector Array based implementation of a Permutation data structure. Integrates Knuth's Algorithm L to find next Lexicographic Permutation.
 * 
 * @author Jeremy Perez
 * @date January 2023
*/

/**
 * Returns number at a specified index of the permutation, if not then -1
*/
int mockPermutation::getAtIndex(const int index) const{
    if(index < 0 || index >= this->length){
        return this->ERROR;
    }
    return this->permSequence[index]; 
}

/**
 * Traverses through mockPermutation to find the index of a specified value, if not found, returns -1
 * @return an index in permSequence where <valueToFind> can be found
 * --ASSUMES mockPermutation IS UNIQUE--
*/
int mockPermutation::findValue(const int valueToFind) const{
    for(int i=0; i < getLength();i++){
        if( valueToFind == this->permSequence[i]){
            return i;
        }
    }
    return -1;
}

/**
 * Calculates value of the ID mockPermutation at a specified index 
*/ 
int mockPermutation::getIdentityPosition(const int index) const
{
    return index+1;
}

/**
* Non-default constructor that initiates an Identity Permuation at size N
* @param N specifies the length of the mockPermutation
*/
mockPermutation::mockPermutation(const int N){
    this->length = N;
    for(int i=1; i <= N; i++){
        this->permSequence.push_back(i);
    }
}

/**
* Non-default constructor that initiates a Permuation of size <len> using the <sequence>
* @param len specifies the length of the array being passed in
* @param sequence[] specifies the mockPermutations values in order from beginning to end
*/
mockPermutation::mockPermutation(const int len, const int sequence[]){
    this->length = len;
    for(int i=0; i < this->length; i++){
        this->permSequence.push_back(sequence[i]); 
    }
}

/**
* Non-default constructor that initiates a Permuation with a size of the <sequence> vector and using the <sequence> values
* @param sequence specifies the values in order that want to be passed in as a mockPermutation 
*/
mockPermutation::mockPermutation(const vector<int> sequence){
    this->length = (int) sequence.size();
    this->permSequence = sequence;
}

/**
 * Gives the ID mockPermutations matching index value within this mockPermutation
 * @param idVal value inside ID mockPermutation 
*/
int mockPermutation::apply(const int idVal) const {
    int valIndex = idVal-1;
    return getAtIndex(valIndex);
}
/**
 * Returns the length of the mockPermutation
*/
int mockPermutation::getLength() const{
    return (int) this->permSequence.size();
}

/**
 * Creates a new mockPermutation which uses this mockPermutation's values and maps them at each of <p2> values locations
 * e.g perm{1,2,3}.compose(perm{2,1,3}) will produce the mockPermutation {2,1,3}
 * @param p2 equally sized permuation which values will be used as indexs
*/
mockPermutation mockPermutation::compose(const mockPermutation p2) const{

    int composedSequence[getLength()];

    for (int i = 0; i < getLength(); i++){
        int locationIndex = p2.getAtIndex(i) - 1;
        composedSequence[locationIndex] = getAtIndex(i);
    }

    mockPermutation composedPerm = mockPermutation(getLength(), composedSequence);

    return composedPerm;
}

/**
 * Returns permuation's values spaced out in order. 
*/
string mockPermutation::toString() const{
    string perm = "";

    for (int i = 0; i < getLength(); i++)
    {
        if(i == 0){
            perm = to_string(getAtIndex(i));
            continue;
        }
        perm = perm + " " + to_string(getAtIndex(i));
    }

    return perm;      
}

/**
 * Checks if permuation is an Identity Permuation
 * e.g perm{1,2,3} --> True, perm{2,1,3} --> False
*/
bool mockPermutation::isId() const{
    return isId(this->permSequence);
}

// Helper
bool mockPermutation::isId(const vector<int> sequence) const{
    for(int x=0; x<sequence.size(); x++){
        if (sequence[x] != getIdentityPosition(x)){
            return false;
        }
    }
    return true;
    }

/**
 * Compares this Permuation's STRING values to <p2> STRING values and returns there comparisons
 * @return an integer which implies the relationship between the two mockPermutations are the following
 * 0 --> Both permuations are the same
 * >0 --> p2's characters are bigger --> p2's sequence as an integer is bigger than this mockPermutation's
 * <0 --> this permuation's characters are bigger --> p1's sequence as an integer is bigger than this mockPermutation's
*/
int mockPermutation::compareTo(const mockPermutation p2) const{
    return toString().compare(p2.toString());
}

/**
 * Returns if <p2> is equal to this permuation
*/
bool mockPermutation::equals(const mockPermutation p2) const{
    return  compareTo(p2) == 0;
}

/**
 * Returns next Lexicographic mockPermutation using Knuth's Algorithm L. If last permuation is found, returns Identity mockPermutation.
*/
mockPermutation mockPermutation::Next()const{

    // Finds the last element where the next element is bigger
    
    int startingIndex = getLength() - 1; // Because we are starting from the last index
    do{
        //We need to grab the second last index
        startingIndex--;

        // Case: It's the last mockPermutation so returns identity
        if(startingIndex == -1){
            return mockPermutation(getLength());
            break;
        }
    }
    while(getAtIndex(startingIndex) >= getAtIndex(startingIndex+1));

    int startingVal = getAtIndex(startingIndex);

    // Finds the smallest number after index that is bigger than step 1
    int smallestNumLocationAfterStart =  startingIndex + 1;
    int smallestNumAfterStart = getAtIndex(smallestNumLocationAfterStart);

    for(int i = smallestNumLocationAfterStart; i < getLength(); i++){
        int currentNum = getAtIndex(i);
        if(currentNum > startingVal && currentNum < smallestNumAfterStart){
            smallestNumLocationAfterStart = i;
            smallestNumAfterStart = currentNum;
        }
    }

    // Swap step 1 and step 2
    
    vector<int> newPermSequence = this->permSequence;

    swap(newPermSequence[startingIndex], newPermSequence[smallestNumLocationAfterStart]);

    sort(newPermSequence.begin() + startingIndex + 1, newPermSequence.end());

    return mockPermutation(newPermSequence);
}

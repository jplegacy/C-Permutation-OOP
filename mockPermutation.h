
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/**
 * Vector Array based implementation of a mockPermutation data structure. Integrates Knuth's Algorithm L to find next Lexicographic mockPermutation.
 * 
 * @author Jeremy Perez
 * @date January 2023
*/

#pragma once

class mockPermutation{
    private:
        /**
         * INVARIANT:
         *  - permSequence keeps track of every value in the mockPermutation in order by index
         *  - e.g permSequence = [1,2,3] implies the mockPermutation 1,2,3 (ID Perm) and permSequence = [3,1,2] implies the sequence 3,1,2
         *  - Vector will always have a size equal to the length of the mockPermutation
         *  - Identity mockPermutation value can always be computed when given an index using the following [index + 1]
         *      (Also implying, values inside of the permutation are always +1 a respective value in an ID Perm)
         *  - Values will remain unique within permSequence
        */
        int length;
        vector<int> permSequence;
        int ERROR = -1;

        /**
         * Returns number at a specified index of the mockPermutation
        */
        int getAtIndex(const int index) const;
        
        /**
         * Traverses through mockPermutation to find the index of a specified value, if not found, returns -1
         * @return an index in permSequence where <valueToFind> can be found
         * --ASSUMES mockPermutation IS UNIQUE--
        */
        int findValue(const int valueToFind) const;

        /**
         * Calculates value of the ID mockPermutation at a specified index 
        */ 
        int getIdentityPosition(const int index) const;

        // Helper
        bool isId(const vector<int> sequence) const; 


    public:
       /**
        * Non-default constructor that initiates an Identity Permuation at size N
        * @param N specifies the length of the mockPermutation
       */
        mockPermutation(const int N) ;

       /**
        * Non-default constructor that initiates a Permuation of size <len> using the <sequence>
        * @param len specifies the length of the array being passed in
        * @param sequence[] specifies the mockPermutations values in order from beginning to end
       */
        mockPermutation(const int len,const int sequence[]);

       /**
        * Non-default constructor that initiates a Permuation with a size of the <sequence> vector and using the <sequence> values
        * @param sequence specifies the values in order that want to be passed in as a mockPermutation 
       */
        mockPermutation(const vector<int> sequence);
        /**
         * Gives the ID mockPermutations matching index value within this mockPermutation
         * @param idVal value inside ID mockPermutation 
        */
        int apply(const int idVal) const;
        /**
         * Returns the length of the mockPermutation
        */
        int getLength() const;

        /**
         * Creates a new mockPermutation which uses this mockPermutation's values and maps them at each of <p2> values locations
         * e.g perm{1,2,3}.compose(perm{2,1,3}) will produce the mockPermutation {2,1,3}
         * @param p2 equally sized permuation which values will be used as indexs
        */
        mockPermutation compose(const mockPermutation p2) const;

        /**
         * Returns permuation's values spaced out in order. 
        */
        string toString() const;

        /**
         * Checks if permuation is an Identity Permuation
         * e.g perm{1,2,3} --> True, perm{2,1,3} --> False
        */
        bool isId() const;

        /**
         * Compares this Permuation's STRING values to <p2> STRING values and returns there comparisons
         * @return an integer which implies the relationship between the two mockPermutations are the following
         * 0 --> Both permuations are the same
         * >0 --> p2's characters are bigger --> p2's sequence as an integer is bigger than this mockPermutation's
         * <0 --> this permuation's characters are bigger --> p1's sequence as an integer is bigger than this mockPermutation's
        */
        int compareTo(const mockPermutation p2) const;

        /**
         * Returns if <p2> is equal to this permuation
        */
        bool equals(const mockPermutation p2) const;

        /**
         * Returns next Lexicographic mockPermutation using Knuth's Algorithm L. If last permuation is found, returns Identity mockPermutation.
        */
        mockPermutation Next() const;

};


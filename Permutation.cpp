#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/**
 * Vector Array based implementation of a Permutation. Integrates Knuth's Algorithm L to find next Lexicographic Permutation.
 * 
 * @author Jeremy Perez
 * @date January 2023
*/
class Permutation{
    private:
        /**
         * INVARIANT:
         *  - permSequence keeps track of every value in the permutation in order by index
         *  - e.g permSequence = [1,2,3] implies the permutation 1,2,3 (ID Perm) and permSequence = [3,1,2] implies the sequence 3,1,2
         *  - Vector will always have a size equal to the length of the permutation
         *  - Identity Permutation value can always be computed when given an index using the following [index + 1]
         *  - Values will remain unique within permSequence
        */
        int length;
        vector<int> permSequence;
    
        /**
         * Returns number at a specified index of the permutation
        */
        int getAtIndex(int index){
            return permSequence[index]; 
        }

        /**
         * Returns the length of the permutation
        */
        int getLength(){
            return (int) permSequence.size();
        }

        /**
         * Swaps values at atA and toB inside permSequence 
        */
        void swapIndexs(int atA, int toB){
            swapIndexs(permSequence, atA, toB);
        }

        // Helper
        void swapIndexs(vector<int> seq, int atA, int toB){
            int temp = seq[atA];
            seq[atA] = seq[toB];
            seq[toB] = temp;
        }

        /**
         * Traverses through Permutation to find the index of a specified value, if not found, returns -1
         * @return an index in permSequence where <valueToFind> can be found
         * --ASSUMES PERMUTATION IS UNIQUE--
        */
        int findValue(int valueToFind){
            for(int i=0; i < getLength();i++){
                if( valueToFind == permSequence[i]){
                    return i;
                }
            }
            return -1;
        }

        /**
         * Calculates value of the ID permutation at a specified index 
        */ 
        int getIdentityPosition(int index)
        {
            return index+1;
        }

    public:
       /**
        * Non-default constructor that initiates an Identity Permuation at size N
        * @param N specifies the length of the permutation
       */
        Permutation(int N){
            length = N;
            for(int i=1; i <= N; i++){
                permSequence.push_back(i);
            }
        }

       /**
        * Non-default constructor that initiates a Permuation of size <len> using the <sequence>
        * @param len specifies the length of the array being passed in
        * @param sequence[] specifies the permutations values in order from beginning to end
       */
        Permutation(int len, int sequence[]){
            length = len;
            for(int i=0; i < length; i++){
                permSequence.push_back(sequence[i]); 
            }
        }

       /**
        * Non-default constructor that initiates a Permuation with a size of the <sequence> vector and using the <sequence> values
        * @param sequence specifies the values in order that want to be passed in as a permutation 
       */
        Permutation(vector<int> sequence){
            length = (int) sequence.size();
            permSequence = sequence;
        }

        /**
         * Gives the ID permutations matching index value within this permutation
         * @param idVal value inside ID Permutation 
        */
        int apply(int idVal){
            
            int valIndex = idVal-1;

            return getAtIndex(valIndex);
        }

        /**
         * Creates a new permutation which uses this permutation's values and maps them at each of <p2> values locations
         * e.g perm{1,2,3}.compose(perm{2,1,3}) will produce the permutation {2,1,3}
         * @param p2 equally sized permuation which values will be used as indexs
        */
        Permutation compose(Permutation p2){

            int composedSequence[getLength()];

            for (int i = 0; i < getLength(); i++){
                int locationIndex = p2.getAtIndex(i) - 1;
                composedSequence[locationIndex] = getAtIndex(i);
            }

            Permutation composedPerm = Permutation(getLength(), composedSequence);

            return composedPerm;
        }

        /**
         * Returns permuation's values spaced out in order. 
        */
        string toString(){
            string perm = "";
            for (int i = 0; i < getLength(); i++)
            {
                perm = perm + " " + to_string(getAtIndex(i));
            }

            return perm;      
        }

        /**
         * Checks if permuation is an Identity Permuation
         * e.g perm{1,2,3} --> True, perm{2,1,3} --> False
        */
        bool isId(){
            return isId(permSequence);
        }

        // Helper
        bool isId(vector<int> sequence){
            for(int x=0; x<sequence.size(); x++){
                if (sequence[x] != getIdentityPosition(x)){
                    return false;
                }
            }
            return true;
            }

        /**
         * Compares this Permuation's STRING values to <p2> STRING values and returns there comparisons
         * @return an integer which implies the relationship between the two permutations are the following
         * 0 --> Both permuations are the same
         * >0 --> p2's characters are bigger --> p2's sequence as an integer is bigger than this permutation's
         * <0 --> this permuation's characters are bigger --> p1's sequence as an integer is bigger than this permutation's
        */
        int compareTo(Permutation p2){
            return toString().compare(0, getLength(), p2.toString());
        }

        /**
         * Returns if <p2> is equal to this permuation
        */
        bool equals(Permutation p2){
            return  compareTo(p2) == 0;
        }

        /**
         * Returns next Lexicographic Permutation using Knuth's Algorithm L. If last permuation is found, returns Identity permutation.
        */
        Permutation Next(){

            // Finds the last element where the next element is bigger
            
            int startingIndex = getLength() - 1; // Because we are starting from the last index
            do{
                //We need to grab the second last index
                startingIndex--;

                // Case: It's the last permutation
                if(startingIndex == -1){
                    return Permutation(getLength());
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
            
            vector<int> newPermSequence = permSequence;

            swapIndexs(newPermSequence,startingIndex,smallestNumLocationAfterStart);

            // Sort substring after index in increasing order

            sort(newPermSequence.begin() + startingIndex + 1, newPermSequence.end());

            return Permutation(newPermSequence);
        }

};

int main(){

    int seq[] =  {1,2,4,3};
    Permutation test = Permutation(4,seq);
    // cout << test.toString()<<"\n";

    int seq2[] =  {3,2,1,4};
    Permutation test2 = Permutation(4,seq2);
    // cout << test2.toString()<<"\n";


    // int location = test.apply(3);
    // cout << test.isId() <<"\n";

    
    // Permutation result = test.compose(test2);
    // cout << result.toString();

    vector<int> seq3 =  {3,1,2};
    Permutation test3 = Permutation(seq3);

    Permutation next = test3.Next();
    cout << next.toString() << "\n";    

}
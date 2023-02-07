#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/**
 * Array based implementation of an individual Permutation. Can be used to find the next Permutation
 * 
 * @author Jeremy Perez
 * @date 01/13/2023
*/
class Permutation{
    private:
        /**
         * INVARIANT:
         *  - permSequence keeps track of each value in the permutation which is represented as an index
         *  - e.g permSequence = [1,2,3] implies the sequence 1,2,3 (ID Perm) and permSequence = [3,1,2] implies the sequence 3,1,2
         *  - Will always have a size equal to the length
         *  - Identity Permutation value can always be computed when given an index using the following [index + 1]
        */
        int length;
        vector<int> permSequence;
    
        int getAtIndex(int index){
            return permSequence[index]; 
        }

        int getLength(){
            return (int) permSequence.size();
        }

        void swapIndexs(int atA, int toB){
            permSequence = swapIndexs(permSequence, atA, toB);
        }
        
        vector<int> swapIndexs(vector<int> seq, int atA, int toB){
            int temp = seq[atA];
            seq[atA] = seq[toB];
            seq[toB] = temp;

            return seq;
        }

        // Traverses through Permutation to find the index of a specified value, if not found, returns -1
        int findValue(int valueToFind){
            for(int i=0; i < getLength();i++){
                if( valueToFind == permSequence[i]){
                    return i;
                }
            }
            return -1;
        }

        // Calculates value of the ID permutation at a specified index 
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
         * @param i value inside ID Permutation 
        */
        int apply(int i){
            return getAtIndex(valueToFind-1);
        }

        /**
         * 
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
        string toString(){
            string perm = "";
            for (int i = 0; i < getLength(); i++)
            {
                perm = perm + " " + to_string(getAtIndex(i));
            }

            return perm;      
        }

        bool isId(){
            return isId(permSequence);
        }

        bool isId(vector<int> sequence){
            for(int x=0; x<sequence.size(); x++){
                if (sequence[x] != getIdentityPosition(x)){
                    return false;
                }
            }
            return true;
            }

        int compareTo(Permutation p2){
            return toString().compare(p2.toString());
        }
        bool equals(Permutation p2){
            return  compareTo(p2) == 0;
        }

        Permutation Next(){

            // Finds the last element where the next element is bigger
            
            int startingIndex = getLength() - 1; //Because we are starting from the last index
            do{
                //We need to grab the second last index
                startingIndex--;

                // Case: It's the last permutation
                if(startingIndex == -1){
                    return Permutation(permSequence);
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

            newPermSequence = swapIndexs(newPermSequence,startingIndex,smallestNumLocationAfterStart);

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
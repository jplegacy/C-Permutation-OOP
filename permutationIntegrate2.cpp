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
         *  - RelativeIndexLocations keeps track of changes made to the each item in the sequence
         *  - e.g RIL = [0,0,0] implies the sequence 1,2,3 (ID Perm) and RIL = [1,-1,0] implies the sequence 2,1,3
         *  - Will always be length of the sequence and every possible 
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

        int findValue(int valueToFind){
            for(int i=0; i < getLength();i++){
                if( valueToFind == permSequence[i]){
                    return i;
                }
            }
            return -1;
        }
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

        Permutation(int len, int sequence[]){
            length = len;
            for(int i=0; i < length; i++){
                permSequence.push_back(sequence[i]); 
            }
        }

        Permutation(vector<int> seq){
            length = (int) seq.size();
            permSequence = seq;
        }

        /**
         * Locates the index of a specified integer in the next Permutation
         * @param i the index of the specified integer in the Permutation
         * @return the ith integer's index in the next permutatoin
        */
        int apply(int valueToFind){
            return permSequence[valueToFind-1];
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
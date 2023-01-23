#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Array based implementation of an indivdual Permutation. Can be used to find the next Permutation
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
        vector<int> relativeIndexLocations;

        int getAtIndex(int index){
            return (index + 1) - relativeIndexLocations[index]; 
        }

        void setRIL(int index, int pointToIndex){
            relativeIndexLocations[index] =  (pointToIndex + 1) - index; 
        }

        int get_length(){
            return relativeIndexLocations.size;
        }

        int findIndexOf(int numToSearchFor){
            for(int i = 0; i< this->get_length();i++){
                if(this.getAtIndex(i) == numToSearchFor){
                    return i;
                }
            }
            return 0;
        }

    public:
       /**
        * Non-default constructor that initiates an Identity Permuation at size N
        * @param N specifies the length of the permutation
       */
        Permutation(int N){
            int* sequence = emptySequenceGenerator(N);
            relativeIndexLocations = new vector(sequence);
        }

        /**
         * Locates the index of a specified integer in the next Permutation
         * @param i the index of the specified integer in the Permutation
         * @return the ith integer's index in the next permutatoin
        */
        int apply(Permutation p2, int i){

            int numInPerm = this.getAtIndex(i);
            int indexOfLocation = p2.findIndexOf(i);

            
            ;
        }

        /**
         * 
        */
        Permutation compose(Permutation p2){
            ;
        }
        string toString(){
            string perm = "";
            for (i = 0; i < len; i++)
            {
                /* code */
            }
            

            ;
        }
        bool isId(){
            return strcmp(this.toString() == );
            ;
        }
        int compareTo(){
            ;
        }
        bool Equals(Permutation p2){
            return strcmp(this.toString(), p2.toString());
        }

        Permutation Next(){
            for(int r : relativeIndexLocations)
            ;
        }


};

int* emptySequenceGenerator(int N){
    int sequence[N];

    for(int i; i<N; i++){
        sequence[i] = 0;
    }
    return sequence;
}



int main(){
    Permutation test = Permutation(5);
}
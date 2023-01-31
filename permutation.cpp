#include <iostream>
#include <string>
#include <vector>

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
        vector<int> relativeIndexLocations;

        int getAtIndex(int index){
            return (index + 1) - relativeIndexLocations[index]; 
        }
        int getRelativeAtIndex(int index){
            return relativeIndexLocations[index]; 
        }

        void setRIL(int index, int pointToIndex){
            relativeIndexLocations[index] =  (pointToIndex + 1) - index; 
        }

        int get_length(){
            return (int) relativeIndexLocations.size();
        }

        void swapIndexs(int atA, int toB){
            swap(relativeIndexLocations[atA],relativeIndexLocations[toB]);
        }

        static int* emptySequenceGenerator(int N){
            int sequence[N] ;

            for(int i; i < N; i++){
                sequence[i] = 0;
            }
            return sequence;
        }

    public:
       /**
        * Non-default constructor that initiates an Identity Permuation at size N
        * @param N specifies the length of the permutation
       */
        Permutation(int N){
            int* sequence = emptySequenceGenerator(N);
            relativeIndexLocations<int> vect(sequence);
        }

        /**
         * Locates the index of a specified integer in the next Permutation
         * @param i the index of the specified integer in the Permutation
         * @return the ith integer's index in the next permutatoin
        */
        int apply(Permutation p2, int i){
            int currentRelativeVal = this.getRelativeAtIndex(i)
            int relativeTransformation = p2.getRelativeAtIndex(i);
            

            if(currentRelativeVal + relativeTransformation >= this.length){

            }
            
            this ->swapIndexs(numInPerm, indexOfLocation);

        }

        /**
         * 
        */
        Permutation compose(Permutation p2){
            ;
        }
        string toString(){
            string perm = "";
            for (int i = 0; i < this->get_length(); i++)
            {
                perm += this->getAtIndex(i);
            }
            
            return perm;      
        }
        bool isId(){
            for(int x=0; x<this->length; x++){
                if (this->getRelativeAtIndex(x) != 0){
                    return false;
                }
            }

            return true;
        }
        int compareTo(){
            ; 
        }
        bool equals(Permutation p2){
            return this->toString().compare(p2.toString()) == 0;
        }

        Permutation Next(){
            for(int r : relativeIndexLocations)
            ;
        }

};





int main(){
    Permutation test = Permutation(5);
}
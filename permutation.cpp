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

    public:
       /**
        * Non-default constructor that initiates an Identity Permuation at size N
        * @param N specifies the length of the permutation
       */
        Permutation(int N){
            for(int i; i < N; i++){
                relativeIndexLocations.push_back(i);
            }
        }

        Permutation(int* sequence){
            for(int i=0; i < sizeof(sequence); i++){
                relativeIndexLocations.push_back(sequence[i]);
            }
        }
        /**
         * Locates the index of a specified integer in the next Permutation
         * @param i the index of the specified integer in the Permutation
         * @return the ith integer's index in the next permutatoin
        */
        int apply(Permutation p2, int index){
            int newIndex = index + p2.getRelativeAtIndex(index);
            this->swapIndexs(index, newIndex);
            
            int newRIL = this->getRelativeAtIndex(index) + p2.getRelativeAtIndex(index);
            this->relativeIndexLocations[index] = newRIL;

            newRIL = this->getRelativeAtIndex(newIndex) + p2.getRelativeAtIndex(newIndex);
            relativeIndexLocations[newIndex] = newRIL;

            return 0;
        }

        /**
         * 
        */
        Permutation compose(Permutation p2){
            return Permutation(1);
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
            return 0;
        }
        bool equals(Permutation p2){
            return this->toString().compare(p2.toString()) == 0;
        }

        Permutation Next(){
            for(int r : relativeIndexLocations){}
            ;
            return Permutation(1);
        }

};


int main(){
    Permutation test = Permutation(5);
    int seq[] =  {1,2,4,3};

    Permutation test2 = Permutation(seq);

}
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
        vector<int> permSequence;

        int getAtIndex(int index){
            return permSequence[index]; 
        }
        int get_length(){
            return (int) permSequence.size();
        }

        void swapIndexs(int atA, int toB){
            int temp = permSequence[atA];
            permSequence[atA] = permSequence[toB];
            permSequence[toB] = temp;
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
            length = permSequence.size();
        }
        /**
         * Locates the index of a specified integer in the next Permutation
         * @param i the index of the specified integer in the Permutation
         * @return the ith integer's index in the next permutatoin
        */
        int apply(int valueToFind){
            return permSequence[valueToFind-1];

        }

        int findValue(int valueToFind){
            for(int i=0; i < get_length();i++){
                if( valueToFind == permSequence[i]){
                    return i;
                }
            }
            return -1;
        }
        /**
         * 
        */
        Permutation compose(Permutation p2){

            int composedSequence[get_length()];

            for (int i = 0; i < get_length(); i++){
                int locationIndex = p2.getAtIndex(i);
                composedSequence[locationIndex] = getAtIndex(i);
            }

            Permutation composedPerm = Permutation(get_length(), composedSequence);

            return composedPerm;
        }
        string toString(){
            string perm = "";
            for (int i = 0; i < get_length(); i++)
            {
                perm = perm + to_string(getAtIndex(i));
            }

            return perm;      
        }
        int getIdentityPosition(int index)
        {
            return index+1;
        }

        bool isId(){
            for(int x=0; x<get_length(); x++){
                if (getAtIndex(x) != getIdentityPosition(x)){
                    return false;
                }
            }
            return true;
        }
        int compareTo(){
            return 0;
        }
        bool equals(Permutation p2){
            return toString().compare(p2.toString()) == 0;
        }

        Permutation Next(){
            for(int r : permSequence){}
            ;
            return Permutation(1);
        }

};

int main(){
    Permutation test = Permutation(5);
    int seq[] =  {1,2,4,3};

    Permutation test2 = Permutation(4,seq);

    cout << test2.toString()<<test2.get_length()<<"\n";

    int location = test2.apply(3);
    cout << test2.isId() <<"\n";

    Permutation result = test2.compose(test2);



    cout << result.toString() <<"\n";

}
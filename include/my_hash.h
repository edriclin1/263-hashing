#include "superhero.h"
#include <vector>

/**
* Class for a My_hash object. 
* 
* @author Edric Lin
* @version 2/4/2018
*/

class My_hash {
public:
    
    /**
    * Default constructor for My_hash object. 
    */
    My_hash() {
        superheroList.reserve(SIZE);
    }

    int hash(const std::string& key) {
        int hashVal = 0;
 
        for(char ch:key){
            hashVal += ch;
        }

        return hashVal % SIZE;
    }

    int hash1(const std::string& key) {
        return (key[ 0 ] + 27 * key[ 1 ] + 729 * key[ 2 ]) % SIZE;
    }

    unsigned int hash2(const std::string& key) {
        unsigned int hashVal = 0;
 
        for (char ch:key ){
            hashVal = 37 * hashVal + ch;
        }
 
        return hashVal % SIZE;
    }

    bool insert(const Superhero & s, int func_num) {

        // get superhero name
        std::string name = s.getName();

        int index = 0;

        // get index from hashing functions
        if (func_num == 0) {
            index = hash(name);
        }

        if (func_num == 1) {
            index = hash1(name);
        }

        if (func_num == 2) {
            index = hash2(name);
        }

        // increase capacity (may not need)
        superheroList[index].reserve(superheroList[index].capacity() + 1);

        // insert superheros at in list corresponding to hash
        superheroList[index].insert(superheroList[index].begin(), s);

        // check if collision (i.e. capacity is greater than 1)
        return (superheroList[index].size() > 1);
    }

    Superhero& get(const std::string name, int func_num) {

        int index = 0;

        // get index from hashing functions
        if (func_num == 0) {
            index = hash(name);
        }

        if (func_num == 1) {
            index = hash1(name);
        }

        if (func_num == 2) {
            index = hash2(name);
        }

        // return first item at vector index
        return superheroList[index][0];
    }
    
private:

    /** vectors of vectors for superheros hashing functions */
    std::vector< std::vector<Superhero>>  superheroList;

    /** size of the hashmap */
    const int SIZE = 17011;

};
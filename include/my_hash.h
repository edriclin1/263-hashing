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
        superheroList.reserve(17011);
    }

unsigned int hash(const std::string& key, int tableSize){
    int hashVal = 0;
 
    for(char ch:key){
        hashVal += ch;
    }
    return hashVal % tableSize;
}

unsigned int hash2( const std::string& key, int tableSize ){
        return (key[ 0 ] + 27 * key[ 1 ] + 729 * key[ 2 ]) % tableSize;
}

unsigned int hash3(const std::string& key, int tableSize){
    unsigned int hashVal = 0;
 
    for (char ch:key ){
        hashVal = 37 * hashVal + ch;
    }
 
    return hashVal % tableSize;
}

bool insert(const Superhero& s, unsigned int (*hash)(const std::string &, int)) {

    // get superhero name
    std::string name = s.get_name();

    // get index from hashing function
    int index = (int) hash(name, 17011);

    // increase capacity of vector by 1
    int capacity = (int) superheroList[index].capacity() + 1;
    (superheroList[index]).reserve(capacity);

    // insert into beginning of vector
    it = superheroList[index].begin();      // http://www.cplusplus.com/reference/vector/vector/insert/
    (superheroList[index]).insert (it , s);

    // check if collision (i.e. capacity is greater than 1)
    if (capacity > 1) {
        return true;
    }
    return false;
}

Superhero& get(const std::string name, std::function<double (double,double)> func)) {

}
    
private:

    /** vector of size  */
    std::vector< std::vector<Superhero>>  superheroList;
};
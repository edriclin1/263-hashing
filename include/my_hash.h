#ifndef MY_HASH_H
#define MY_HASH_H

#define SIZE 17011

#include "superhero.h"

#include <vector>
#include <iostream>

/**********************************************************
* Class for a My_hash object. Contains a vector of vectors
* that holds superhero objects.
* 
* @author Edric Lin
* @author Hai Duong
* @author Trungvuong Pham
* @version 3/20/2018
***********************************************************/

class My_hash {
public:
    
    /*******************************************************
    * Default constructor for My_hash object. 
    * Sets the capacity of vectors.
    *******************************************************/
    My_hash() {
        superheroList.reserve(SIZE);
    }

    /******************************************************
    * Deconstructor detroys the data structure
    * ****************************************************/	
    ~My_hash() {}

    /******************************************************
    * First hashing method counts all the chars of key 
    * and adds them. Then returns the sum modded by SIZE.
    *
    * @param key the key to hash
    * @return the hashmap index
    *******************************************************/
    int hash(const std::string& key) {
        
	//storage for the summed chars count
	int hashVal = 0;
 
	//loops through key then sums into hashVal
        for(char ch:key){
            hashVal += ch;
        }
	
	//returns the modded size of the list
        return hashVal % SIZE;
    }


    /*******************************************************
    * Second hashing method takes the values based on
    * first three chars of key summed them together
    * and modded by SIZE.
    *
    * @param key the key to hash
    * @return the hashmap index
    *******************************************************/
    int hash1(const std::string& key) {
        return (key[ 0 ] + 27 * key[ 1 ] + 729 * key[ 2 ]) % SIZE;
    }

    /******************************************************
    * Third hashing method takes an unsigned int then goes
    * through each key and multiplies by 37 then add the char
    * value. The sum is modded by SIZE.
    *
    * @param key the key to hash
    * @return the hashmap index
    *******************************************************/
    unsigned int hash2(const std::string& key) {
        
	//storage for the summed chars count
	unsigned int hashVal = 0;
 	
	//loops through key to add to the hashVal
        for (char ch:key ){
            hashVal = 37 * hashVal + ch;
        }
 	
	//returned the unsigned size
        return hashVal % SIZE;
    }

    /******************************************************
    * Method to insert a Superhero object into the 
    * vector of vectors using one of the hashing functions.
    *
    * @param s the superhero to return
    * @param func_num the function number to use (0-2)
    * @return whether there was a collision
    *******************************************************/
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

    /******************************************************
    * Method to retrieve a superhero from the hashmap using 
    * a specific hashing function.
    *
    * @param name the superhero name to hash and retrieve
    * @param func_num the function number to use (0-2)
    * @return the superhero object
    ******************************************************/
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

};

#endif

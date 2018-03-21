-----------------------------------------------------------------------------


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

Number of collisions in function [0]: 14077


-----------------------------------------------------------------------------


    int hash1(const std::string& key) {
        return (key[ 0 ] + 27 * key[ 1 ] + 729 * key[ 2 ]) % SIZE;
    }

Number of collisions in function [1]: 13893


-----------------------------------------------------------------------------


    unsigned int hash2(const std::string& key) {
        unsigned int hashVal = 0;
 
        for (char ch:key ){
            hashVal = 37 * hashVal + ch;
        }
 
        return hashVal % SIZE;
    }

Number of collisions in function [2]: 5894


-----------------------------------------------------------------------------

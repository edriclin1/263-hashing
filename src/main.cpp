#include "csv.h"
#include "my_hash.h"
#include "superhero.h"
#include <string>
#include <iostream>

/**
* Main method to read a csv file of Marvel superheros into
* Superhero objects and put them into a hashmap.
* 
* @author Edric Lin
* @author Hai Duong
* @author Trungvuong Pham
* @version 3/20/2018
*/

int main(int argc, char** argv) {

    // if not 2 arguments, error
    if (argc != 2) {
        std::cout << "> Usage: ./prog_name hashing_function (0-2)" << std::endl;
        exit(1);
    }

    // check function argument
    if (std::stoi(argv[1]) != 0 && std::stoi(argv[1]) != 1 && std::stoi(argv[1]) != 2) {
        std::cout << "> Please enter a valid hashing function number (0-2)." << std::endl;
        exit(1);
    }

    // create new My_hash object
    My_hash* my_hash = new My_hash();

    // track collisions
    int collisions = 0;

    io::CSVReader<13, io::trim_chars<' '>, io::double_quote_escape<',','\"'> > in("marvel-wikia-data.csv");
    in.read_header(io::ignore_extra_column, "page_id", "name", "urlslug", "ID", "ALIGN", "EYE", "HAIR", "SEX", "GSM", "ALIVE", "APPEARANCES", "FIRST APPEARANCE", "Year");

    int page_id;
    std::string name;
    std::string urlslug;
    std::string id;
    std::string alignment;
    std::string eye_color;
    std::string hair_color;
    std::string sex;
    std::string gsm;
    std::string alive;
    std::string appearances;
    std::string first_appearance;
    std::string year;

    while(in.read_row(page_id, name, urlslug, id, alignment, eye_color, hair_color, sex, gsm, alive, appearances, first_appearance, year)){

        char eye_conv = (eye_color.empty()) ? '_' : eye_color.at(0);
        char hair_conv = (hair_color.empty()) ? '_' : hair_color.at(0);
        char sex_conv = (sex.empty()) ? '_' : sex.at(0);
        bool alive_conv = (!alive.empty() && alive.at(0) == 'D') ? false : true;
        int appearances_conv = (appearances.empty()) ? '_' : stoi(appearances);
        int year_conv = (year.empty()) ? '_' : stoi(year);

        // create new superhero object
        Superhero* temp = new Superhero(page_id, name, urlslug, id, alignment, eye_conv, hair_conv, sex_conv, gsm, alive_conv, appearances_conv, first_appearance, year_conv);

        if (my_hash -> insert(*temp, std::stoi(argv[1]))) {
            collisions++;
        }
    }
    std::cout << "Number of collisions in function [" << argv[1] << "]: " << collisions << std::endl;
}


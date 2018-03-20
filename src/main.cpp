#include "csv.h"
#include "my_hash.h"
#include "superhero.h"
#include <string>
#include <iostream>

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
    int appearances;
    std::string first_appearance;
    int year;

    while(in.read_row(page_id, name, urlslug, id, alignment, eye_color, hair_color, sex, gsm, alive, appearances, first_appearance, year)){

        // convert char traits from string
        char eye_conv = eye_color.at(0);
        char hair_conv = hair_color.at(0);
        char sex_conv = sex.at(0);

        // convert bool trait from string (living if starts with L)
        bool alive_conv = (alive.at(0) == 'L');

        // create new superhero object
        Superhero* temp = new Superhero(page_id, name, urlslug, id, alignment, eye_conv, hair_conv, sex_conv, gsm, alive_conv, appearances, first_appearance, year);

        if (my_hash -> insert(*temp, std::stoi(argv[1]))) {
            collisions++;
        }
    }
    std::cout << "Number of collisions: " << collisions << std::endl;
}


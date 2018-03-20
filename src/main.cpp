#include "csv.h"
#include "my_hash.h"
#include <string>
#include <iostream>

int main(int argc, char** argv) {

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
      
    }
    // std::cout << page_id << ", " << name << ", " << urlslug << ", " << id << ", " << alignment << ", " << eye_color << ", " << hair_color << ", " << sex << ", " << gsm << ", " << alive << ", " << appearances << ", " << first_appearance << ", " << year << std::endl;
}
#include <iostream>
#include <iostream>
#include <string>

#include "superhero.h"

Superhero::Superhero(int page_id, std::string name, std::string urlslug, std::string id,
			std::string alignment, char eye_color, char hair_color, char sex,
			std::string gsm, int alive, int appearances, std::string first_appearance,
			int year) :

		page_id(page_id), name(name), urlslug(urlslug), id(id), alignment(alignment), eye_color(eye_color), hair_color(hair_color), sex(sex), gsm(gsm), alive(alive), appearances(appearances), first_appearance(first_appearance), year(year) {}


std::string Superhero::getName() const  {return name;}

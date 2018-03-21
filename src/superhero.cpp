#include <iostream>
#include <iostream>
#include <string>

#include "superhero.h"

/************************************************************
* Class implementation for Superhero class. 
* 
* @author Edric Lin
* @author Hai Duong
* @author Trungvuong Pham
* @version 3/20/2018
***********************************************************/

/**********************************************************
* Default constructor for the superhero object.
**********************************************************/
Superhero::Superhero(int page_id, std::string name, std::string urlslug, std::string id,
			std::string alignment, char eye_color, char hair_color, char sex,
			std::string gsm, bool alive, int appearances, std::string first_appearance,
			int year) :

		page_id(page_id), name(name), urlslug(urlslug), id(id), alignment(alignment), eye_color(eye_color), hair_color(hair_color), sex(sex), gsm(gsm), alive(alive), appearances(appearances), first_appearance(first_appearance), year(year) {}

/**********************************************************
 * Method to return the superhero name.
 * 
 * @return the superhero name
 **********************************************************/
std::string Superhero::getName() const  {return name;}

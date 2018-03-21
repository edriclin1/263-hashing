#ifndef SUPERHERO_H
#define SUPERHERO_H

#include <iostream>
#include <string>

/************************************************
* Header file for Superhero class.
* 
* @author Edric Lin
* @author Hai Duong
* @author Trungvuong Pham
* @version 3/20/2018
*************************************************/

class Superhero {
private:

	//Each trait that each superhero contains
	int page_id;
	std::string name;
	std::string urlslug;
	std::string id;
	std::string alignment;
	char eye_color;
	char hair_color;
	char sex;
	std::string gsm;
	bool alive;
	int appearances;
	std::string first_appearance;
	int year;

public:

    	/**************************************************
    	 * Default constructor for the superhero object.
    	************************************************ */
	Superhero(int page_id, std::string name, std::string urslug, std::string id, std::string alignment,
			char eye_color, char hair_color, char sex, std::string gsm,
			bool alive, int appearances, std::string first_appearance,
			int year);
	
	//method to get the names of each superhero
	std::string getName() const;

};



#endif

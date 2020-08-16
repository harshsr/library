#pragma once
#include "std_lib_facilities.h"
#include "isbn.h"

enum class genre
{
	unknown, fiction, nonfiction, periodical, biography, children
};


//to check if entered int is valid for genre
bool bad_genre(int a)
{
	if (a<int(genre::unknown) || a> int(genre::children))
	{
		cout << "\nBad genre.";
		return true;
	}
	else
		return false;
}

//to be able to print the enum, following vector is defined
vector<string> genre_vector = { "unknown","Fiction","Non-fiction","Periodical","Biography","Children" };

class book_info
{
private:
	string title;
	string author_name;
	int copyright_year;
	isbn ISBN{ 978,0,0,0,'5' };
	bool in_stock = true;
	genre genre1;

public:
	//non modifying functions

	string get_title() const {
		return title;
	}

	string get_author() const {
		return author_name;
	}

	int get_copyright_year() const {
		return copyright_year;
	}

	isbn get_isbn() const {
		return ISBN;
	}

	bool get_availability() const {
		return in_stock;
	}

	genre get_genre()
	{
		return genre1;
	}

	void print_book_info() const;

	//modifying functions

	void input_book_info();


	//default constructor with some default values.
	book_info()
	{
		title = "0";
		author_name = "0";
		copyright_year = 1950;
	}
	
};



#include "book_info.h"
#include "std_lib_facilities.h"

//definition of function that prompts the user to enter book info.
void book_info::input_book_info()
{
	try
	{
		//title
		cout << "\nEnter the title of the book. Enter '/' to stop\n";
		vector<string> title_vector;
		string s;
		int i = 0;
		while (cin >> s && s != "/")
		{
			title_vector.push_back(s);
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');                                                        //getting rid of input buffer
		title.clear();
		for (i = 0; i < title_vector.size(); ++i)
		{
			title = title + " " + title_vector[i];
		}

		//author
		cout << "\nEnter the name of author of the book. Enter '/' to stop\n";
		vector<string> author_vector;
		while (cin >> s && s != "/")
		{
			author_vector.push_back(s);
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		author_name.clear();
		for (i = 0; i < author_vector.size(); ++i)
		{
			author_name = author_name + " " + author_vector[i];
		}

		//copyright year
		cout << "\nEnter the year of copyright.\n";
		cin >> copyright_year;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//ISBN
		ISBN.init_isbn();

		//genre
		cout << "Enter the number corrosponding to the book genre.\nUnknown :\t0\nFiction :\t1\nNon-fiction :\t2\nPeriodical :\t3\nBiography :\t4\nChildren :\t5\n";
		int book_genre;
		cin >> book_genre;
		if (bad_genre(book_genre) == false)
			genre1 = genre(book_genre);

		//availibility
		cout << "\nIs the book available in the library? Enter yes or no.\n";
		cin >> s;
		if (s == "yes")
			in_stock = true;
		else
			in_stock = false;
	}
	catch (const std::exception&)
	{
		cout << "bad_input";
	}
	catch (range_error)
	{
		cout << "bad_input";
	}

}


//definition of function that displays the book info.
void book_info::print_book_info() const
{
	cout << "\nName of the book:\t" << title << "\nName of the author:\t" << author_name << "\nCopyright year:\t\t" << copyright_year << "\nISBN:\t\t\t" << ISBN.get_isbn() << "\nGenre:\t\t\t" << genre_vector[int(genre1)];

	if (in_stock == true)
		cout << "\nThe book is in stock.\n";
	else
		cout << "\nThe book is out of stock.\n";
}


int main()
{
	book_info rcvd;
	rcvd.input_book_info();
	rcvd.print_book_info();
}
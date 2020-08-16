#include"std_lib_facilities.h"
class isbn
{
private:
	int pre_element;                                                                      //prefix element
	int reg_grp_element;                                                                  //registration group element
	int reg_element;                                                                      //registrant element
	int pub_element;                                                                      //publication element
	char check_digit;
	string final_isbn;

public:
	class invalid_isbn {};


	string get_isbn() const
	{
		return final_isbn;
	}

	//check if the ISBN is valid. this is just a simple test
	bool check_validity() 
	{
		try
		{
			if (pre_element == 978 || pre_element == 979)
			{
				int length1 = to_string(reg_grp_element).length();
				if (length1 > 5)
				{
					throw invalid_isbn{};
					return false;
				}

				int length2 = to_string(reg_element).length();
				if (length2 > 7)
				{
					throw invalid_isbn{};
					return false;
				}

				int length3 = to_string(pub_element).length();
				if (length3 > 6)
				{
					throw invalid_isbn{};
					return false;
				}

				return true;
			}
			else
			{
				throw invalid_isbn{};
				return false;
			}
		}
		catch (const std::exception&)
		{
			cout << "\nInvalid ISBN\n";
		}
		catch (invalid_isbn) {
			cout << "\nInvalid ISBN\n";
		}
	}


	//constructor
	isbn()
	{
		pre_element = 0;
		reg_grp_element = 0;
		reg_element = 0;
		pub_element = 0;
		check_digit = '0';
	}
	isbn(int a, int b, int c,int d,char e )
	{
		pre_element = a;
		reg_grp_element = b;
		reg_element = c;
		pub_element = d;
		check_digit = e;
		if (check_validity()==true) {
			string s1 = to_string(pre_element);
			string s2 = to_string(reg_grp_element);
			string s3 = to_string(reg_element);
			string s4 = to_string(pub_element);
			string s5 = to_string(check_digit);

			final_isbn = s1 + "-" + s2 + "-" + s3 + "-" + s4 + "-" + s5;
		}
	}


	//to avoid the implicit conversion from int to char in case the user tries to feed all ints in above constructor
	isbn(int, int, int, int, int) = delete;


	//initialization by user
	void init_isbn() 
	{
		cout << "\nenter ISBN no. use spaces instead of '-'.\n";
		cin >> pre_element;
		cin >> reg_grp_element;
		cin >> reg_element;
		cin >> pub_element;
		cin >> check_digit;
		if (check_validity()==true) {
			string s1 = to_string(pre_element);
			string s2 = to_string(reg_grp_element);
			string s3 = to_string(reg_element);
			string s4 = to_string(pub_element);
			string s5 = to_string(check_digit);

			final_isbn = s1 + "-" + s2 + "-" + s3 + "-" + s4 + "-" + s5;
		}
	}


	//print isbn
	void print_isbn()
	{
		if (check_validity()==true)
		{
			cout << "\n" << final_isbn << "\n";
		}
	}
};


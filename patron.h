#include"std_lib_facilities.h"

class patron
{
private :
	string patron_name;
	int card_number;
	bool fee_status;
	int fee_amount;

public:
	class invalid_card_no {};


	//constructors
	patron()
	{
		patron_name = "NoName";
		card_number = 0;
		fee_status = false;
		fee_amount = 0;
	}

	patron(string a, int b, bool c, int d)
	{
		try
		{
			int length = to_string(b).length();
			patron_name = a;
			if (length == 4)
			{
				card_number = b;
			}
			else
			{
				throw invalid_card_no{};
			}
			fee_status = c;
			fee_amount = d;
		}
		catch (invalid_card_no)
		{
			cout << "\nInvalid card number.\n";
		}
		
	}

	//non modifying functions
	string get_patron_name() const
	{
		return patron_name;
	}

	int get_card_no() const
	{
		return card_number;
	}

	bool get_fee_status() const
	{
		return fee_status;
	}

	int get_fee_amount() const
	{
		return fee_amount;
	}

	//modifying functions
	void set_patron_name(string a)
	{
		patron_name = a;
	}

	void set_card_no(int a)
	{
		card_number = a;
	}

	void set_fee_status(bool a)
	{
		fee_status = a;
	}

	void modify_fee_amount(int a)
	{
		fee_amount = fee_amount + a;
		if (fee_amount == 0)
			fee_status = false;
	}
};


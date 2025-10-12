#include <iostream>
#include "ChooseMenu.h"
using namespace std;

int main()
{
	int choice = 0;

	while(choice!=7)
	{
		cout << "\t-------Welcome to University Resturant-------" << endl;
		cout << "\t1.Menu" << endl << "\t2.New_Order" << endl << "\t3.Order_Delivered" << endl;
		cout << "\t4.Cancel_Order" << endl << "\t5.Change_Order" << endl << "\t6.Review" << endl;
		cout << "\t7.Exit" << endl;
		cout << "\t";
		cin >> choice;
		choosemenu menu(choice);
	}
	return 0;

}
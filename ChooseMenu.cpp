#include <iostream>
#include "ChooseMenu.h"

choosemenu::choosemenu(int c)
{
	choice = c;
	

	switch (c)
	{
	case 1:
		//menu();
		break;

	case 2:
		//neworder();
		break;

	case 3:
		//orderdeliverd();
		break;

	case 4:
		//CancelOrder();
		break;

	case 5:
		//ChangeOrder();
		break;

	case 6:
		//Review();
		break;

	case 7:
		cout << "\n\tQuiting The App" << endl;
		//exit();
		break;

	default:
		cout << "\n\tIncorrect Input" << endl;
		break;
	}
}

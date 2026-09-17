#include<iostream>
#include "clsLoginScreen.h"
using namespace std;

int main()

{
    while (true)
    {

        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }

	cout << "\n\n\t\tThanks for using our system.\n\n";

    return 0;

}
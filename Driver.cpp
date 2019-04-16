#include <iostream>
#include <sstream>
#include <string>
#include <ctring>
#include "PriorityQ.hpp"
using namespace std;

void menu()
{
  cout << "============TerrificAirlines Booking Agency============" << endl;
  cout << "1. Search flights" << endl;
  cout << "2. Book tickets" << endl;
  cout << "2. Cancel tickets" << endl;
  cout << "4. Reschedule flights" << endl;
  cout << "5. Print flight information" << endl;
  cout << "6. Quit" << endl;
  cout << "More feature?" <<endl;

}

int main(int argc, char*argv[])
{
  PriorityQueue First(25);
  PriorityQueue Buss(50);
  PriorityQueue Econ(100);

  int option,Cpassenger;
  string hold,depart,arrive;

  while(1)
  {
    menu();
    getline(cin,hold);
    option = stoi(hold);
    switch(option)
    {
      case 1:
      {
        cout<<"Please type the depart location"<<endl;
        getline(cin,depart);
        cout<<"Please type the destination"<<endl;
        getline(cin,arrive);

        //check edges
        break;
      }
      case 2:
      {
        cout<<"Please enter your full name"<<endl;
        ////////////
        First.enqueue (_PName, _Depart, _Arrive, _Bclass, _Bagnum);
        break;
      }
      case 3:
      {
        break;
      }
      case 4:
      {
        break;
      }
      case 5:
      {
        break;
      }
      case 6:
      {
        cout<<"Goodbye"<<endl;
        return 0;
      }
    }

  }

}

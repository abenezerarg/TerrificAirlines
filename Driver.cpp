#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
// #include <ctring>
#include "PriorityQ.hpp"
using namespace std;

void menu()
{
  cout << "============TerrificAirlines Booking Agency============" << endl;
  cout << "1. Search flights" << endl;
  cout << "2. Book tickets" << endl;
  cout << "3. Reschedule flights" << endl;
  cout << "4. Print flight information" << endl;
  cout << "5. Quit" << endl;

}

// void getCapitalCities(Cities &tree)
// {
//   ifstream capital("stateCapitals.txt");
//
//   if(capital.is_open())
//   {
//     string city;
//     while(!capital.eof())
//     {
//       getline(capital, city);
//       tree.addCity(city);
//     }
//   capital.close();
//   }
// }

int main(int argc, char*argv[])
{
  PriorityQueue First(25);
  PriorityQueue Buss(50);
  PriorityQueue Econ(100);

  Cities *tree;

  // getCapitalCities(*tree);

  ifstream example("Example.txt");
  if(example.is_open())
  {
    string name, depart, arrive, _BClass, temp;
    int _Bagnum;
    while(!example.eof())
    {
      getline(example, name, ',');
      getline(example, depart, ',');
      getline(example, arrive, ',');
      getline(example, _BClass, ',');
      getline(example, temp);
      stringstream to(temp);
      to >> _Bagnum;
      if(_BClass.compare("First") == 0 || _BClass.compare("first") == 0)
      First.enqueue (name, depart, arrive, _BClass, _Bagnum);
      if(_BClass.compare("Business") == 0 || _BClass.compare("business") == 0)
      Buss.enqueue (name, depart, arrive, _BClass, _Bagnum);
      if(_BClass.compare("Economy") == 0 || _BClass.compare("economy") == 0)
      Econ.enqueue (name, depart, arrive, _BClass, _Bagnum);
    }
    example.close();
  }

  int option, _Bagnum;
  string hold,_BClass,depart,arrive, name;

  while(1)
  {
    menu();
    getline(cin,hold);
    option = stoi(hold);
    switch(option)
    {
      case 1:
      {
        break;
      }
      case 2:
      {
        cout<<"Departaure city: ";
        getline(cin,depart);
        while(!tree->isInTree(depart))
        {
          cout << "TerrificAirlines only operates in capital cities in the United States: ";
          getline(cin,depart);
        }
        cout<<"Arrival city: ";
        getline(cin,arrive);
        while(!tree->isInTree(arrive))
        {
          cout << "TerrificAirlines only operates in capital cities in the United States: ";
          getline(cin,arrive);
        }
        cout << "Enter traveling class(First, Business, or Economy): ";
        getline(cin, _BClass);
        while(_BClass.compare("First") != 0 && _BClass.compare("first") != 0 && _BClass.compare("Business") != 0 && _BClass.compare("business") != 0 && _BClass.compare("Economy") != 0 && _BClass.compare("economy") != 0)
        {
          cout << "Please enter one of the listed classes: ";
          getline(cin,_BClass);
        }
        cout << "How many bags will you be traveling with: ";
        cin >> _Bagnum;
        cin.ignore();
        cout<<"Enter your full name: ";
        getline(cin, name);
        if(_BClass.compare("First") == 0 || _BClass.compare("first") == 0)
        First.enqueue (name, depart, arrive, _BClass, _Bagnum);
        if(_BClass.compare("Business") == 0 || _BClass.compare("business") == 0)
        Buss.enqueue (name, depart, arrive, _BClass, _Bagnum);
        if(_BClass.compare("Economy") == 0 || _BClass.compare("economy") == 0)
        Econ.enqueue (name, depart, arrive, _BClass, _Bagnum);
        break;
      }
      case 3:
      {
        break;
      }
      case 4:
      {
        cout << "Name of passenger: ";
        getline(cin, name);
        cout << "Traveling class: ";
        getline(cin, _BClass);
        if(_BClass.compare("First") == 0 || _BClass.compare("first") == 0)
        First.search(name, 0);
        if(_BClass.compare("Business") == 0 || _BClass.compare("business") == 0)
        Buss.search(name, 25);
        if(_BClass.compare("Economy") == 0 || _BClass.compare("economy") == 0)
        Econ.search(name, 50);

        break;
      }
      case 5:
      {
        cout<<"Thank you for visiting TerrificAirlines"<<endl;
        return 0;
      }
    }

  }

}

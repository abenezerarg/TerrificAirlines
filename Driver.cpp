#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "PriorityQ.hpp"
#include "Graph.hpp"
#include <iomanip>

using namespace std;
//problem, what happen if two people have the same name?
void menu()
{
  cout << "============TerrificAirlines Booking Agency============" << endl;
  cout << "1. Book tickets" << endl;
  cout << "2. Cancel tickets" << endl;
  cout << "3. Reschedule flights" << endl;
  cout << "4. Print passenger information" << endl;
  cout << "5. Quit" << endl;

}


int main(int argc, char*argv[])
{
    ifstream inStream1;
    string temp, l;
    Graph g;
    string each;
    string much;
    int i;
    int dist, dura;
    vector <string> verti;
    inStream1.open("stateCapitals.txt");
    getline(inStream1, temp);
    stringstream ss;
    ss << temp;
    getline(ss, l, ',');
    cout << "Cities TerrificAirlines flys from or to:" << endl;
    while(getline(ss, l, ',')){
      cout << " - " << l << endl;
      g.addVertex(l);
      verti.push_back(l);
    }
    ss.clear();
    while(getline(inStream1, temp)){
      i = 0;
      ss << temp;
      getline(ss, each, ',');
      while(getline(ss, much, ',')){
        dist = stoi(much);
        getline(ss, much, ',');
        dura = stoi(much);
        if(dist > 0 && dura > 0){
          g.addEdge(each, verti[i], dist, dura);
        }
        i++;
      }
      ss.clear();
    }
    PriorityQueue First(25);
    PriorityQueue Buss(50);
    PriorityQueue Econ(100);
    //Graph G;
    int option,Cpassenger, bagnum;
    string hold,depart,arrive,_PName, _Depart, _Arrive, _Bclass,_Bagnum;
    int _PindexF = 0;
    int _PindexB = 0;
    int _PindexE = 0;

    while(1)
    {
      menu();
      getline(cin,hold);
      option = stoi(hold);
      switch(option)
      {

        case 1:
        {
          g.bookFlight();
          break;
        }
          case 2:
          {
            string name,depart,arrive;
            bool check = false, checkedge = false;
            while (!check)
            {
              cout<<"Please enter your class before you cancel (First Class / Business Class / Economy Class)"<<endl;
              getline(cin, _Bclass);
              if(_Bclass == "First Class" || _Bclass == "Business Class" || _Bclass =="Economy Class")
              {
                check = true;
              }
              else
              {
                cout<<"Please enter (First Class / Business Class / Economy Class)"<<endl;
                cout<<endl;
                check = false;
              }
            }
            cout<<"Please enter your name"<<endl;
            getline(cin, name);
            cout<<"Please enter the Departure city of your flight"<<endl;
            getline(cin, depart);
            cout<<"Please enter the Arrive city of your flight"<<endl;
            getline(cin,arrive);
            if(_Bclass == "First Class")
            {
              Edge * temp = g.findEdge(depart,arrive);
              if(temp !=nullptr)
              {
                  temp->firstClass->cancelflight(name);
              }

            }

            else if(_Bclass == "Business Class")
            {
              Edge *temp = g.findEdge(depart,arrive);
              if(temp !=nullptr)
              {
                temp->businessClass->cancelflight(name);
              }



            }
            else if(_Bclass == "Economy Class")
            {

              Edge *temp = g.findEdge(depart,arrive);
              if(temp !=nullptr)
              {
                temp->coachClass->cancelflight(name);
              }
            }
            else
            {
              cout <<"The class you input is not a vaild class"<<endl;
            }
            break;
          }
          case 3:
          {
            string name,depart,arrive;
            bool check = false, checkedge = false;
            while (!check)
            {
              cout<<"Please enter your class before you cancel (First Class / Business Class / Economy Class)"<<endl;
              getline(cin, _Bclass);
              if(_Bclass == "First Class" || _Bclass == "Business Class" || _Bclass =="Economy Class")
              {
                check = true;
              }
              else
              {
                cout<<"Please enter (First Class / Business Class / Economy Class)"<<endl;
                cout<<endl;
                check = false;
              }
            }
            cout<<"Please enter your name"<<endl;
            getline(cin, name);
            cout<<"Please enter the Departure city of your flight"<<endl;
            getline(cin, depart);
            cout<<"Please enter the Arrive city of your flight"<<endl;
            getline(cin,arrive);
            if(_Bclass == "First Class")
            {
              Edge * temp = g.findEdge(depart,arrive);
              if(temp !=nullptr)
              {
                  temp->firstClass->cancelflight(name);
              }

            }

            else if(_Bclass == "Business Class")
            {
              Edge *temp = g.findEdge(depart,arrive);
              if(temp !=nullptr)
              {
                temp->businessClass->cancelflight(name);
              }



            }
            else if(_Bclass == "Economy Class")
            {

              Edge *temp = g.findEdge(depart,arrive);
              if(temp !=nullptr)
              {
                temp->coachClass->cancelflight(name);
              }
            }
            else
            {
              cout <<"The class you input is not a vaild class"<<endl;
            }
            g.bookFlight();

            break;
          }
          case 4:
      {
        string name;
        cout << "Name of passenger: ";
        getline(cin, name);
        cout << "Traveling class: ";
        getline(cin, _Bclass);
        cout<<"Departing from: ";
        getline(cin,_Depart);
        while(!g.findVertex(_Depart))
        {
          cout << "TerrificAirlines does not have any flight available to that city: ";
          getline(cin,_Depart);
        }
        cout<<"Destination: ";
        getline(cin,_Arrive);
        while(!g.findVertex(_Arrive))
        {
          cout << "TerrificAirlines does not have any flight available to that city: ";
          getline(cin,_Arrive);
        }
        g.passengerInfo(name, _Depart, _Arrive, _Bclass);
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

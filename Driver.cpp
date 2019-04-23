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
  cout << "1. Search flights (Still in Maintenence)" << endl;
  cout << "2. Book tickets" << endl;
  cout << "3. Cancel tickets" << endl;
  cout << "4. Reschedule flights" << endl;
  cout << "5. Print passenger information" << endl;
  cout << "6. Print flight information(Still in Maintenence)" << endl;
  cout << "7. Quit" << endl;
  cout << "More feature coming soon..." <<endl;

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
          cout<<"Please type the depart location"<<endl;
          getline(cin,depart);
          cout<<"Please type the destination"<<endl;
          getline(cin,arrive);

          //check edges
          break;
        }
        case 2:
        {
          g.bookFlight();
          break;
        }
          case 3:
          {
            string name;
            bool check = false;
            while (!check)
            {
              cout<<"Please enter your class before you cancel (First/Buss/Econ)"<<endl;
              getline(cin, _Bclass);
              if(_Bclass == "First" || _Bclass == "Buss" || _Bclass =="Econ")
              {
                check = true;
              }
              else
              {
                cout<<"Please enter (First/Buss/Econ)"<<endl;
                cout<<endl;
                check = false;
              }
            }
            cout<<"Please enter your name"<<endl;
            getline(cin, name);
            if(_Bclass == "First")
            {
              if(First.cancelflight(name))
              cout<<name<<" Your flight has been canceled"<<endl;
            }
            else if(_Bclass == "Buss")
            {
              if(Buss.cancelflight(name))
              cout<<name<<" Your flight has been canceled"<<endl;

            }
            else if(_Bclass == "Econ")
            {
              if(Econ.cancelflight(name))
              cout<<name<<" Your flight has been canceled"<<endl;

            }
            else
            {
              cout <<"The class you input is not a vaild class"<<endl;
            }
            break;
          }
          case 4:
          {//cancel flights
            string name;
            cout<<"Please enter your class your ticket is in (First/Buss/Econ)"<<endl;
            getline(cin, _Bclass);
            cout<<"Please enter your name"<<endl;
            getline(cin, name);
            if(_Bclass == "First")
            {
              First.cancelflight(name);
            }
            else if(_Bclass == "Buss")
            {
              Buss.cancelflight(name);
            }
            else if(_Bclass == "Econ")
            {
              Econ.cancelflight(name);
            }
            else
            {
              cout <<"Not a vaild class"<<endl;
            }
            //rebook flight
            cout<<"Please enter your departing airport code"<<endl;
            getline(cin,_Depart);
            cout<<"Please enter your arriveal airport code"<<endl;
            getline(cin,_Arrive);
            // if(G.Searchflight(_Depart,_Arrive))
            // {

            cout<<"Please enter number of bag"<<endl;
            getline(cin,_Bagnum);
            bagnum = stoi(_Bagnum);
            cout<<"Please enter First/Buss/Econ tickets class"<<endl;
            getline(cin,_Bclass);
            if(_Bclass == "First")
            {
              First.enqueue (_PName,depart,arrive,_Bclass ,bagnum);
            }
            else if(_Bclass == "Buss")
            {
              Buss.enqueue (_PName,depart,arrive,_Bclass ,bagnum);
            }
            else if(_Bclass == "Econ")
            {
              Econ.enqueue (_PName,depart,arrive,_Bclass ,bagnum);
            }
            else
            {
              cout <<"Not a vaild class"<<endl;
            }
            // }
            // else
            // {
            //   cout<<"We have no flght to flight there, please traval somewhere else"<<endl;
            // }
            break;
          }
          case 5:
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
          case 6:
          {
            cout << "displayEdges" <<endl;
            g.displayEdges();
            cout << "BFT" << endl;
            g.printBFT();
            cout << "DFT" << endl;
            g.printDFT();
            break;
          }
          case 7:
          {
            cout<<"Thank you for visiting TerrificAirlines"<<endl;
            return 0;
          }
        }
      }
}

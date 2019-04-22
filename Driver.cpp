#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "PriorityQ.hpp"
#include "Graph.hpp"

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
  if(argc != 2){
    cout << "Usage: REQUIRED: <inputfilename.txt> " << endl;
    return -1;
  }else{
    ifstream inStream1;
    string temp, l;
    Graph g;
    string each;
    string much;
    int i;
    int dist, dura;
    vector <string> verti;
    inStream1.open(argv[1]);
    getline(inStream1, temp);
    stringstream ss;
    ss << temp;
    getline(ss, l, ',');
    while(getline(ss, l, ',')){
      cout << l << endl;
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
          cout << " ... Reading in " << each << " -- " << verti[i] << " -- " << dist <<  " -- " << dura <<endl;
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
          string Bcheck;
          bool check= false;
          bool checkB = false;
          bool checkF = false;
          bool checkE = false;
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
          // if(G.Searchflight(_Depart,_Arrive))
          // {
          cout<<"Please enter your full name"<<endl;
          getline(cin,_PName);

          while(!check)
          {
            cout<<"Please enter number of bag"<<endl;
            getline(cin,_Bagnum);
            bagnum = stoi(_Bagnum);
            if(bagnum > 0 && bagnum <=3)
            {
              check = true;
            }
            else
            {
              check = false;
              cout<<"Sorry, please enter the vail input, we only allow 3 bags at most"<<endl;
            }
          }
          check = false;
          while(!check)
          {

            cout<<"Please enter First/Buss/Econ tickets class"<<endl;
            getline(cin,_Bclass);
            if(_Bclass == "First" || _Bclass == "Buss" || _Bclass =="Econ")
            {
              check = true;
            }
            else
            {
              check= false;
              cout<<"Please enter (First/Buss/Econ)"<<endl;
            }
          }
          check = false;
          while(!check)
          {
            cout<<"The price of this trip will be $2, do you want to book this trip? Please enter (Yes/No)"<<endl;
            getline(cin,Bcheck);
            if(Bcheck == "Yes")
            {
              check = true;
              if(_Bclass == "First")
              {
                if(First.enqueue (_PName, _Depart, _Arrive, bagnum,_PindexF))
                {
                  checkF = true;
                  _PindexF++;
                }
                else
                {
                  cout<<"book ticket fail"<<endl;
                }
              }
              else if(_Bclass == "Buss")
              {
                if(Buss.enqueue (_PName, _Depart, _Arrive, bagnum,_PindexB))
                {
                  checkB = true;
                  _PindexB++;
                }
                else
                {
                  cout<<"book ticket fail"<<endl;
                }
              }
              else if(_Bclass == "Econ")
              {
                if(Econ.enqueue(_PName, _Depart, _Arrive, bagnum,_PindexE))
                {
                  checkE = true;
                  _PindexE++;
                }
                else
                {
                  cout<<"book ticket fail"<<endl;
                }        }
                else
                {
                  cout <<"Not a vaild class, please enter a valid class (First/Buss/Econ)"<<endl;
                }
              } else if (Bcheck == "No") {
                break;
              } else
              {
                cout<<"Please enter (Yes/No)"<<endl;
                check = false;
              }
            }
            if(checkE)
            {
              cout<<"Comfirmation: "<< " Name " << _PName<<"."<<" Depart "<< _Depart<<"." <<" Arrive " << _Arrive <<"."<< " Class: "<< _Bclass<<"."<< " Group number " << _PindexE <<endl;
              cout<<endl;
              checkE = false;
            }
            if(checkB)
            {
              cout<<"Comfirmation: "<< " Name " << _PName<<"."<<" Depart "<< _Depart<<"." <<" Arrive " << _Arrive <<"."<< " Class: "<< _Bclass<<"."<< " Group number " << _PindexB <<endl;
              cout<<endl;
              checkE = false;
            }
            if(checkF)
            {

              cout<<"Comfirmation: "<< " Name " << _PName<<","<<" Depart "<< _Depart <<"."<<" Arrive " << _Arrive<<"." << " Class: "<< _Bclass<<"."<< " Group number " << _PindexF <<endl;
              cout<<endl;
              checkF = false;

            }

            //}
            // else
            // {
            //   cout<<"We have no flght to flight there, please traval somewhere else"<<endl;
            // }
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
              First.enqueue (name, _Depart, _Arrive, bagnum,_PindexF);
            }
            else if(_Bclass == "Buss")
            {
              Buss.enqueue (name, _Depart, _Arrive, bagnum,_PindexB);
            }
            else if(_Bclass == "Econ")
            {
              Econ.enqueue(name, _Depart, _Arrive, bagnum,_PindexE);
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

}

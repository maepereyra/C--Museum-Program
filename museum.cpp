/*******************************************************************
Mae Pereyra
CS 211
homework on template functions
09/20/21
*****************************************************************/
#include <iostream> 
#include "array.h"
using namespace std;
#include "/cs/slott/cs211/checkInput.h" 

//prortypes
int showMenu();
void getVisitorInfor(string& country, int& age, double& time, int s);
bool checkPassword();
template <class T>
void showStatistic(T& o, const string country[], const int age[], const double time, int s);

int main()
{
  const int SIZE = 2; //up to 100 visitors
  string ar_C[SIZE]; //array of country
  int ar_A[SIZE]; //array of age
  double ar_T[SIZE]; //array of time spent
  string country; //input
  int age;
  double time;
  int visitor = 0; //visitor counter
  int ans; //choosing 1 or 2
  int pass = 5678; 
  int p; //password for choice 2.
  char yn; //yes or no for the museum to close or not
  string date;
//run the code until necessary
  do{
  cout << "\n============================================================" << endl;
  cout << "1. Vistor" << endl;
  cout << "2. Museum Staff" << endl;
  ans = showMenu();
  //shows which function to show if 1 or 2 is chosen
  switch(ans)
    {
    case 1: getVisitorInfor(country, age, time, SIZE);
      visitor ++;
      break;
    case 2: checkPassword();
      if (checkPassword() == true)
	{
	  showStatistic(cout, country, age, time, SIZE);
	  cout << "Do you want to close the museum? Y or N: ";
	  cin >> yn;
	  if (yn == 'y')
	    {
	      cout << "Enter today's date: ";
	      cin >>  date;
	      filename = date + ".txt";
	      fout.open(filename.c_str());
	      showStatistic(fout, country, age, time, SIZE);
	    }
	}
      else
	{
	  cout << "The password is wrong."; 
	}   
      break;
    }
  }while(ans !=  0); //ans is not equal to 0
  return 0; 
}

/*******************************************************************
ans is the choice of user if 1 or 2

This function will get data and reject if it's the user input is not 1 or 2
*****************************************************************/
int showMenu()
{
  int ans; //answer
  cout << "Enter your choice: ";
  ans = getData(1, 2, "Invalid choice. Enter 1 oer 2: ");
  return ans;

}

/*******************************************************************
country is for the name of country
age is for visitors' age
time is for the time they spent on the museum. 

This function will get the visitor info
*******************************************************************/
void getVisitorInfor(string& country, int& age, double& time, int s)
{
  cout << "\nEnter your country: ";
  cin >> country;
  cout << "Enter your age: ";
  age = getData(0, 200, "The age  has to be between 0 and 200. Enter again: ");
  cout << "Enter the number of hours you explored: ";
  time = getData(0.00, 10.0, "The number of hourse has to be between 0 and 10.0. Enter again: ");
}

/*******************************************************************
cor is for if its true or not
pass is the pasword
p is the user's input
This function will determine if the user input input the right password
*******************************************************************/
bool checkPassword()
{
  int pass = 5678;
  cout << "Enter password: ";
  cin >> p;
  if (p == pass)
    {
      return true;
    }
  else  
    {
      return false;
    }

}
/*******************************************************************

This function shows the statistics of the visitors of the museum
*******************************************************************/
template <class T> 
void showStatistic(T& o, const string country[], const int age[], const double time, int s)
{
  string uniqCntry[count];
  int uniqNum;

  if(count!= 0)
  {
  cout << "The total number of visitors is 0" << endl;
  }
  
  else
    {
      o << "\n------------- The names of the countries of visitors -------" << endl;
      uniqNum = unique(country, uniqCntry, count);
      sort (uniqCntry, uniqNum);
      print( o, uniqCntry, uniqNum);
      o << "\n\nThe age of the youngest visitors: " << age[getLowest(age, count)] << endl;
o << "\n\nThe age of the youngest visitors: " << age[getLowest(age, count)] << endl;
o << "The age of the oldest visitor: " << age[getHighest(age, count)] << endl;
 o << "The average age of the visitors: " << fixed << setprecision(1) << getAvg(age, count) << endl;
o << "\nThe shortest visit hours: " << time[getLowest(time, count)] << endl;

    }
}

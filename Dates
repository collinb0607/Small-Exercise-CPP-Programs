//         Course: CS2400-01 Computer Science II
//           Name: Brooks, Collin
//     Assignment: Assignment #6 class and objects
//  Date assigned: 10/31/2020
//       Date due: 11/10/2020
// Date handed in: 11/10/2020
#include <iostream>

using namespace std;

class date {
    public:
	    date();
	    // Default constructor
	    // Postcondition: the newly created object has been initialized to 1/1/2020

    	date(int, int, int);

 	    void setDate(int mm, int dd, int yyyy);
	    // Mutator
	    // Postcondition: the contents of the calling object are  set of the values passed to the function

  	    int getYear();
  	    //Postcondition: returns the year as a 4 digit integer
  	    
  	    int getMonth();
  	    //Postcondition: returns the month as a 2 digit integer
  	    
  	    int getDay();
  	    //Postcondition: returns the day as a 2 digit integer

	    void setYear(int);
	    //Postcondition: sets the year of date to the given integer

        int compareDates(date& d2);
        // the "calling" date object and d2 are compared
    	// Postcondition: return 1 is the calling object is earlier; returns 0 is they are equal; return -1 is the calling object is later

        void inputDate();
        // prompts the user to enter three values for the calling object
    	// Postcondition: the calling object is loaded with values entered by the user

        void displayDate();
        // Postconodition: the contents of the calling object is displayed in mm/dd/yyyy format, e.g., 10/30/2020

        bool isLeapYear();
        // Postcondition: return true if the year of the calling object is a leap year. (you may need to visit 
   	    //                websites to find out how to determine whether a year is leap year of not.
    private:
        int month;	// 1 - 12
        int day;	// 1 – 31 
        int year;	// Gregorian calendar introduced in Oct., 1582
};

date::date(){
    month = 1;
    day = 1;
    year = 2020;
}

date::date(int mm, int dd, int yyyy){
    month = mm;
    day = dd;
    year = yyyy;
}

void date::setDate(int mm, int dd, int yyyy){
    month = mm;
    day = dd;
    year = yyyy;
}
	
int date::getYear(){
    return year;
}

int date::getMonth(){
    return month;
}

int date::getDay(){
    return day;
}

void date::setYear(int yyyy){
    year = yyyy;
}

int date::compareDates(date& d2){
    if(this->getYear() < d2.getYear())
        return 1;
    else if(this->getYear() == d2.getYear() && this->getMonth() < d2.getMonth())
        return 1;
    else if(this->getYear() == d2.getYear() && this->getMonth() == d2.getMonth() && this->getDay() < d2.getDay())
        return 1;
    else if(this->getYear() == d2.getYear() && this->getMonth() == d2.getMonth() && this->getDay() == d2.getDay())
        return 0;
    return -1;
}   

void date::inputDate(){
    cin >> month >> day >> year;
}

void date::displayDate(){
    cout << month << "/" << day << "/" << year;
}

bool date::isLeapYear(){
    if(year%100 == 0 && year%400 == 0)
        return true;
    else if(year%4 == 0 && year%100 != 0)
        return true;
    return false;
    
}

int main() {
    cout << "The main() begins by declaring thee date objects named d1, d2, and d3." << endl;
    cout << "During declaration, d1 is initialized to 10/30/2020; d2 and d3 are uninitialized;" << endl << endl;
    date d1, d2(10, 30, 2020), d3;
    int rtn;

    cout << "Calling setDate(...) member function to set date object d2 to 9/1/2020" << endl;
    d1.setDate(9, 1, 2020);

    cout << "Calling inputDate() member function to initialize date object d3 to 12/25/2020" << endl;
    d3.inputDate();

    cout << "\nDisplay the d1, d2, and d3;" << endl;
    cout << "   d1: ";  d1.displayDate();  cout << endl;
    cout << "   d2: ";  d2.displayDate();  cout << endl;
    cout << "   d3: ";  d3.displayDate();  cout << endl << endl;
    
    cout << "\nComparing d1 and d2 with d1 being the calling object: " << endl;
    rtn = d1.compareDates(d2);
    
    if (rtn == 1)
    {
        cout << "   ";  
        d1.displayDate(); 
        cout << " is earlier than "; 
        d2.displayDate(); 
        cout << endl;
    }
    else if (rtn == 0)
    {
        cout << "   ";  
        d1.displayDate(); 
        cout << " is the same as "; 
        d2.displayDate(); 
        cout << endl;
    }
    else
    {
        cout << "   ";  
        d1.displayDate(); 
        cout << " is the later than "; 
        d2.displayDate(); 
        cout << endl;
    }
   
    cout << "\nComparing d2 and d3 with d3 being the calling object: " << endl;
    rtn = d3.compareDates(d2);
    
    if (rtn == 1)
    {
        cout << "   ";  
        d3.displayDate(); 
        cout << " is earlier than "; 
        d2.displayDate(); 
        cout << endl;
    }
    else if (rtn == 0)
    {
        cout << "   ";  
        d3.displayDate(); 
        cout << " is the same as "; 
        d2.displayDate(); 
        cout << endl;
    }
    else
    {
        cout << "   ";  
        d3.displayDate(); 
        cout << " is the later than "; 
        d2.displayDate(); 
        cout << endl;
    }

    cout << "\nWe now assign d2 to d3 and then compare d2 and d3 with d2 being the calling object:" << endl;
    d3 = d2;

    rtn = d3.compareDates(d2);

    if (rtn == 1)
    {
        cout << "   ";  
        d3.displayDate(); 
        cout << " is earlier than "; 
        d2.displayDate(); 
        cout << endl;
    }
    else if (rtn == 0)
    {
        cout << "   ";  
 	    d3.displayDate(); 
        cout << " is the same as "; 
        d2.displayDate(); 
        cout << endl;
    }
    else
    {
        cout << "   ";  
        d3.displayDate(); 
        cout << " is the later than "; 
        d2.displayDate(); 
        cout << endl;
    }

    cout << "\nChecking if year of d1 is a leap year: " << endl;
    if (d1.isLeapYear())
        cout << "   Year of d1: " << d1.getYear() << " is a leap year!" << endl;
    else
        cout << "   Year of d1: " << d1.getYear() << " is a leap year!" << endl;

    cout << "\nSet the year of d1 from 2020 to 2019 and check if 2019 is a leap year:" << endl;
    d1.setYear(2019);
    if (d1.isLeapYear())
        cout << "   Year of d1: " << d1.getYear() << " is a leap year!" << endl;
    else
        cout << "   Year of d1: " << d1.getYear() << " is NOT a leap year!" << endl;
}

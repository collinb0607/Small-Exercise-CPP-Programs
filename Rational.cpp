//         Course: CS2400-01 Computer Science II
//           Name: Brooks, Collin
//     Assignment: Assignment #7 Operator Overloading - Rational Numbers 
//  Date assigned: 11/8/2020
//       Date due: 11/15/2020
// Date handed in: 11/15/2020
//         Remark: This is the header file for rational.cpp containing all functions and pre/post conditions
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

using namespace std;

class rational
{
	friend istream& operator>>(istream &in, rational &r);
	// The user is prompted to enter two integer values for the numerator and denominator of a rational 
	// number
	// Postcondition: the calling rational object is assigned with values entered by the user

	friend ostream& operator<<(ostream &out, rational &r);
	// Postcondition: The rational object referenced by r is display as “a / b”, e.g., 1 / 2,  -5 /9 
	// (not 5 / -9), 1 / 4 (not 2 / 8, etc.).

public:
	rational();
	// Postcondition:	declared rational number is initialized to 0 / 1.
	
	rational(int n, int n2);
	// Postcondition:	declared rational number is initialized to n / n.

	void set(int n, int n2);
	// Postcondition: the calling rational object is set to n / n.		
		
	rational operator+(const rational &r2) const;
	// Postcondition: returns the sum of the calling rational object and r2

	rational operator-(const rational &r2) const;
	// Postcondition: returns the difference of subtracting r2 from the calling rational object.

 	rational operator*(const rational &r2) const;
	// Postcondition: returns the product of the calling rational object and r2.
 
	rational operator/(const rational &r2) const;
	// Postcondition: returns the quotient of dividing  the calling rational object  by r2.

	int operator>(const rational&r2) const;
	// Postcondition: returns 1 if the calling object is greater than r2; 0 if it is equal to r2; -1 is 
	// it is less than r2 

private:
	int GCD();
	// A helper member function. You must use the Euclidean algorithm. 
	// https://en.wikipedia.org/wiki/Euclidean_algorithm
	// Postcondition: returns the "greatest common divisor" between the numerator and denominator of 
	// the calling rational object

	int num;	// numerator part of a rational number
	int denom;	// denominator part of a rational number; must not be zero!

	};
#endif

// Non-member external functions
	int fillArray(rational arr[], int size);
	void displayArray(rational arr[], int n);
	void sort(rational arr[], int n);
	void swap(rational &r1, rational &r2);





//         Course: CS2400-01 Computer Science II
//           Name: Brooks, Collin
//     Assignment: Assignment #7 Operator Overloading - Rational Numbers 
//  Date assigned: 11/8/2020
//       Date due: 11/15/2020
// Date handed in: 11/15/2020
//         Remark: This program contains all functions that will be used in rationalMain.cpp
#include <iostream>
#include "rational.h"

using namespace std;

rational::rational(){
	num = 0;
	denom = 1;
}
	
rational::rational(int n, int n2){
	num = n;
	denom = n2;
}

void rational::set(int n, int n2){
	num = n;
	denom = n2;
}
		
rational rational::operator+(const rational &r2) const{
    rational r;
    int denominator = denom * r2.denom;
    int num1 = num * r2.denom;
    int num2 = denom * r2.num;
    r.set(num1+num2, denominator);
    return r;
}

rational rational::operator-(const rational &r2) const{
    rational r;
    int denominator = denom * r2.denom;
    int num1 = num * r2.denom;
    int num2 = denom * r2.num;
    r.set(num1-num2, denominator);
    return r;
}

rational rational::operator*(const rational &r2) const{
	return rational((num * r2.num),(denom * r2.denom));   
}
 
rational rational::operator/(const rational &r2) const{
	return rational((num * r2.denom),(denom * r2.num));
}

int rational::operator>(const rational &r2) const{
	int num1 = (num * r2.denom) - (denom * r2.num);
	if(num1 > 0)
	    return 1;
	if(num1 < 0)
	    return -1;
	return 0;
}

int rational::GCD(){
    int temp;
    if(num == 0)
        return denom;
    else
        this->set(denom%temp,num);
        return GCD();
}

ostream& operator<<(ostream &out, rational &obj){
	out << obj.num << "/" << obj.denom;
	return out;
}

int fillArray(rational arr[], int size){
    int n, num1, num2;
    cout << "You may enter up to " << size << " rational numbers. How many? ";
	cin >> n;
    for(int i = 0; i < n; i++){
        cout << "\tr[" << i+1 << "]:\tEnter values for numerator followed by denominator: ";
        cin >> num1 >> num2;
        arr[i].set(num1, num2);
    }
    return n;
}

void displayArray(rational arr[], int n){
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void sort(rational arr[], int n){
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j] == -1) 
                swap(arr[i], arr[j]);
        }
    }
}

void swap(rational &r1, rational &r2){
    rational r;
    r = r1;
    r1 = r2;
    r2 = r;
}



//         Course: CS2400-01 Computer Science II
//           Name: Brooks, Collin
//     Assignment: Assignment #7 Operator Overloading - Rational Numbers 
//  Date assigned: 11/8/2020
//       Date due: 11/15/2020
// Date handed in: 11/15/2020
//         Remark: This is strictly used to run and test functions used in rational.cpp
#include <iostream>
#include "rational.h"

using namespace std;

int main(){
    int const CAPACITY = 10;
    rational r1, r2;
    rational arr[CAPACITY];
    int num1, num2, size;
    cout << "r1 is initialized by the 2nd constructor: r1 = 1/4" << endl;
    r1.set(1,4);
    cout << "r2 is initialized by the 2nd constructor: r2 = 1/3" << endl;
    r2.set(1,3);
    cout << endl << "Testing the compare() member function, found: " << endl << "\t";
    if(r1 > r2 == 1)
        cout << r1 << " is greater than " << r2 << endl << endl;
    else if(r1 > r2 == -1)
        cout << r1 << " is less than " << r2 << endl << endl;
    else if(r1 > r2 == 0)
        cout << r1 << " is equal to " << r2 << endl << endl;
    cout << "Testing the four arithmetic member functions: " << endl;
    rational sum = r1 + r2;
    cout << "\t" << "r1 + r2 = " << r1 << " + " << r2 << " = " << sum << endl;
    rational diff = r1 - r2;
    cout << "\t" << "r1 - r2 = " << r1 << " - " << r2 << " = " << diff << endl;
    rational product = r1 * r2;
    cout << "\t" << "r1 * r2 = " << r1 << " * " << r2 << " = " << product << endl;
    rational quotient = r1 / r2;
    cout << "\t" << "r1 / r2 = " << r1 << " / " << r2 << " = " << quotient << endl << endl;
    cout << "*** Demonstrate sorting a rational array ***" << endl << endl;
    size = fillArray(arr, CAPACITY);
    cout << endl << "Before sorting, array contains: " << endl;
    displayArray(arr, size);
    cout << endl << "After sorting, array contains: " << endl;
    sort(arr, size);
    displayArray(arr, size);
    return 0;
}



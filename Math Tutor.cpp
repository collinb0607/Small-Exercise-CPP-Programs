//         Course: CS2400-01 Computer Science II
//           Name: Brooks, Collin
//     Assignment: Assignment #2 Loops
//  Date assigned: 9/17/2020
//       Date due: 9/25/2020
// Date handed in: 9/25/2020
//         Remark: The program will act as a math tutor giving various arithmetic problems to solve.

#include <iostream>
#include <iomanip>

using namespace std;

void addition(){
	srand((unsigned) time(0)); //Allows rand() to grab a different number each execution
	int num1 = rand() % 50 + 1;
	int num2 = rand() % 50 + 1;
	int answer = num1 + num2;
	int studentAnswer = num1 + num2;
	cout << setw(5) << num1 << endl << setw(5) << num2 << endl << "+ ---" << endl << "   ";
	cin >> studentAnswer;
	cout << endl;
	if(studentAnswer == answer)
		cout << "Congratulations! That's right." << endl << endl;
	else
		cout << "Sorry, the correct answer is " << answer << "." << endl << endl;
}

void subtraction(){
	srand((unsigned) time(0)); //Allows rand() to grab a different number each execution
	int num1 = rand() % 50 + 1;
	int num2 = rand() % 50 + 1;
	while(num1 < num2){ //Checks to make sure it will be a positive answer
	    num1 = rand() % 50 + 1;
	    num2 = rand() % 50 + 1;
	}
	int answer = num1 - num2;
	int studentAnswer = num1 - num2;
	cout << setw(5) << num1 << endl << setw(5) << num2 << endl << "- ---" << endl << "   ";
	cin >> studentAnswer;
	cout << endl;
	if(studentAnswer == answer)
		cout << "Congratulations! That's right." << endl << endl;
	else
		cout << "Sorry, the correct answer is " << answer << "." << endl << endl;
}

void multipication(){
	srand((unsigned) time(0)); //Allows rand() to grab a different number each execution
	int num1 = rand() % 9 + 1;
	int num2 = rand() % 9 + 1;
	int answer = num1 * num2;
	int studentAnswer = num1 * num2;
	cout << setw(5) << num1 << endl << setw(5) << num2 << endl << "* ---" << endl << "   ";
	cin >> studentAnswer;
	cout << endl;
	if(studentAnswer == answer)
		cout << "Congratulations! That's right." << endl << endl;
	else
		cout << "Sorry, the correct answer is " << answer << "." << endl << endl;
}

void division(){
	srand((unsigned) time(0)); //Allows rand() to grab a different number each execution
	int num1 = rand() % 100 + 1;
	int num2 = rand() % 15 + 1;
	while(num1 <= num2 || num1 % num2 != 0 || num1/num2 > 9){ //Checks to make sure divisor is less than the dividend, will get a whole number as an answer, and the answer will be 9 or less 
	    num1 = rand() % 100 + 1;
	    num2 = rand() % 15 + 1;
	}
	int answer = num1 / num2;
	int studentAnswer = num1 / num2;
	cout << setw(5) << num1 << endl << setw(5) << num2 << endl << "/ ---" << endl << "    ";
	cin >> studentAnswer;
	cout << endl;
	if(studentAnswer == answer)
		cout << "Congratulations! That's right." << endl << endl;
	else
		cout << "Sorry, the correct answer is " << answer << "." << endl << endl;
}

int main(){
    	int choice = 0;
    	char g;
	cout << "\t*** Menu ***" << endl;
	cout << "1. Addition" << endl << "2. Subtraction" << endl << "3. Multipication" << endl << "4. Division" << endl <<  "5. Quit" << endl;
	cout << endl << "Enter your choice <1 - 5>: ";
	cin >> choice;
	if(choice == 1)
		addition();
	else if(choice == 2)
		subtraction();
	else if(choice == 3)
		multipication();
	else if(choice == 4)
		division();
	else if(choice == 5)
		return 0;
	else
	    cout << "Sorry, that is not a valid option." << endl; //Fail safe in case they choose an option not valid
	cout << "Do it again? <y/n>: ";
	cin >> g;
	if(g == 'y'){
	    system("clear"); //Clears everything in preparation to star program from scratch
	    main();
	}
	else //If the person does not put "y" the program will end as if they quit
	    return 0;
}

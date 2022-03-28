// vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

void vectorIntro() {
	vector<string> mybooklist;

	//ADDING ITEMS
	mybooklist.push_back("First Book");//push_back() creaets space then populates it
	mybooklist.push_back("second book");
	mybooklist.push_back("third book");

	//ACESSING VECTORS
	cout << mybooklist[0] << endl;//use array notation. can be used w/loops
	cout << mybooklist[1] << endl;


	cout << "____________________-" << endl;

	//THINGS TO NOTE
	cout << mybooklist.size() << endl;//shows 3
	cout << mybooklist[0].size() << endl; //shows 10

	cout << "____________________________________" << endl;

	//ITERATORS

	/*an iterator is similar to the subscript number associated w/ arrays
	
	  they are NOT the same as integers. They are basically special case pointers
	  
	  
	  
	 Two kinds of iterators
	 
	 -Standard
		-can be used w/any vector
		-can  be used to access or change an element of a vector
		
	-Constant
		-can be used w/ any vector
		-can ONLY be used to access elements
		-an element is not changed through a constant iterator
		*/

	//creating a standard iterator
	//MUST BE THE SAME DATA TYPE as the vector it will be used for

	vector<string>::iterator stdIter;//creates a standard iterator that can be used w/ any vector of strings

	//creating constand iterator
	vector<string>::const_iterator constIter; //creates a constant iterator that can be used w/ any vector of strings

	//useing iterators

	vector<string>Iansbooks;
	Iansbooks.push_back("Harry Pothead");
	Iansbooks.push_back("the DaBaby code");
	Iansbooks.push_back("The Castle McQueen");

	vector<string>::iterator myIter;
	vector<string>::const_iterator cITER;

	cout << "here are your books:" << endl;
	for (cITER = Iansbooks.begin(); cITER != Iansbooks.end(); cITER++) {
		cout << *cITER << endl; //using constant iterator for display

	}

	cout << "You trade Harry Pothead for Waluigi and pieces." << endl;
	myIter = Iansbooks.begin();
	*myIter = "Waluigi and pieces"; //using standard iterator for modification
	cout << Iansbooks[0] << endl;

	//ITERATORS MSUT BE DEFERENCED USING 

	//important vector function
	
	//.push_back () and .pop back()
	//.begin() and .end()
	//.insert()
	//.erase()
	//.clear()
	//.empty()
	//find()                   needs #include <algorithm>
	//random_shuffle()         needs #include <algorithm>
	//sort()                   needs #include <algorithm>
	

}

void 

int main()
{

	//vectorIntro();
	

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

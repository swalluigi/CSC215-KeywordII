// KeywordsII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>//includes the iostream library
#include <vector>//includes the vector library
#include<string>//includes the string library
#include<algorithm>
#include<cstdlib>//includes teh cstdlib library
#include<ctime> // indcludes the ctime library
using namespace std;


int search(string s, char tgt) {//search function, takes a string and char value
	for (int i = 0; i < s.size(); i++) {//for the duration of the string
		if (s[i] == tgt) {//if the letter is found in the word, return i
			return i;
		}
		
	}
	return -1;
}

string makeCode(string s) {//replaces all letters in a word with #
	string ret = s;
	for (int i = 0; i < s.size(); i++) {
		ret[i] = '#';
	}
	return ret;

}

int main()
{
	
	cout << "Code Breater Training program: KeywordsII" << endl;// Display Title of program to user

	cout << "Please log in with your name" << endl;// Ask the recruit to login using thier name
	string recruit;//setus up the recruit variable
	cin >> recruit;// Hold the recruit's name in a var, and address them by it throughout the simulation.
	bool play = true;//sets up the play variable
	int simul = 1; //sets up the simulation count
	cout << "welcome to the simulation, " << recruit << ". Your job is to guess the hidden code word. You have the option to guess a single letter of the word or guess one of the words." << endl;
	cout << "you can also try to guess the entire code word at once, but you will fail the simulation if your answer is incorrect" << endl;
	cout << "all letters are lowercase and all words have underscores between them. Good Luck!" << endl;
	
	while(play==true){//while the play boolean is set to true
		cout << "    " << endl;
		cout << "simulation " << simul << endl;//tells player how many simulation's they have done
		srand(time(0));//initializes the srand function
		vector<string> codes = { "patch","slack","euclid","clef","sonic","blast","crack","klif","float","safe" };// Create a collection of 10 words you had wrote down manual

		string word1 = codes[rand() % codes.size()];//takes a random word from the codes vector
		string word2 = codes[rand() % codes.size()];//takes a random word from the codes vector
		string word3 = codes[rand() % codes.size()];//takes a random word from the codes vector
		string wordAll = word1 + "_" + word2 + "_" + word3;//combines all word
		

		string display1 = makeCode(word1);// sets up the blank word display
		string display2 = makeCode(word2);// sets up the blank word display
		string display3 = makeCode(word3);// sets up the blank word display
		string displayAll = display1 + "_" + display2 + "_" + display3; //combines all displays
		
		int trys = 3;//initiallizes the trys variable
		char usrin_char; // initializes the character user input
		string usrin_str;// initializes the string user input
		char Lguess;// initializes the letter guess variable
		bool correct = true;// initializes the correct answer boolean


		while (trys >0 && displayAll != wordAll) {// while trys is greater than 0 and the player has not guessed the correct word
			cout << "    " << endl;
			
			cout << displayAll << endl;//displays the blank word
			cout << "you have " <<  trys << " attempts left" << endl;
			cout << "    " << endl;
			cout << "guess a letter or guess a word? Type L for letter or W for word. Or you can type A to go all in and guess the entire code word" << endl;
			cin >> usrin_char;//asks the user to input what they want to answer with

			if (usrin_char == 'L'|| usrin_char == 'l') {//if the recruit chooses to enter a letter
				cout << "    " << endl;
				cout << "You Chose to enter a letter" << endl;
				cin >> Lguess;//asks the user to guess a letter
				
				int ret1 = search(word1, Lguess);//searches to see if the guess letter is in the word.
				int ret2 = search(word2, Lguess);//searches to see if the guess letter is in the word.
				int ret3 = search(word3, Lguess);//searches to see if the guess letter is in the word.


				if (ret1 >= 0 || ret2 >= 0 || ret3 >= 0 ) {//if a correct letter is entered
					cout << "correct" << endl;
					if (ret1 >= 0) {
						display1[ret1] = word1[ret1];  //chage the display to show the chosen letter in the selection
					}
					if (ret2 >= 0) {
						display2[ret2] = word2[ret2];//chage the display to show the chosen letter in the selection
					}
					if (ret3 >= 0) {
						display3[ret3] = word3[ret3];//chage the display to show the chosen letter in the selection
					}
					
					displayAll = display1 + "_" + display2 + "_" + display3;

					
					correct = true;//sets the correct boolean to true
				}
				else {//if an incorrect letter is entered.
					cout << "wrong" << endl;
					correct = false;//sets the correct boolean to false
				}
			}
			else if (usrin_char == 'W' || usrin_char == 'w') {//if the recruit chooses to enter a word
				cout << "    " << endl;
				cout << "you have chosen to enter a word" << endl;
				cin >> usrin_str;//askes the recruit to enter a word

				if (usrin_str == word1 || usrin_str == word2|| usrin_str == word3){//if the user enters the correct word
					cout << "correct" << endl;
					correct = true;//sets the correct boolean to true

					if (usrin_str == word1) {//sets the display to show the word
						display1 = word1;
					}
					if (usrin_str == word2) {//sets the display to show the word
						display2 = word2;
					}
					if (usrin_str == word3) {//sets the display to show the word
						display3 = word3;
					}
					
					displayAll = display1 + "_" + display2 + "_" + display3;

				}
				else {//if the recrut guesses the wrong word
					cout << "wrong" << endl;
					correct = false;
				}

				
			}
			else if (usrin_char == 'A' || usrin_char == 'a') {// if the user goes all in
				cout << "    " << endl;
				cout << "you have chosen to go all in. Remember, you fail the simulation if you are incorrect, you will fail." << endl;
				cin >> usrin_str;//askes the recruit to enter a word

				if (usrin_str == wordAll) {//if the user enters the correct code word
					cout << "correct" << endl;
					displayAll = wordAll;//sets diplayAll to wordAll, ending the loop
					correct = true;
				}

				else {//if the user fails to enter the correct code word
					cout << "wrong" << endl;
					trys = 0;//sets the trys to 0, ending the loop and causing a failed simulation
				}
			}

			if (correct == false){
				trys--;
			}
		}
	
		if (trys <= 0) {
			cout << "you have used up all of your chances, " << recruit << ". You have failed" << endl;
			
		}
		else {
			cout << "congradulations, " << recruit << ". You cracked the code." << endl;
		}

		cout << "would you like to play again, " << recruit << "? Y for yes or N for no" << endl;
		cin >> usrin_char;
		if (usrin_char == 'y' || usrin_char == 'Y') {
			play = true;
			simul++;
		}
		else if (usrin_char == 'n' || usrin_char == 'N') {
			play = false;
		}

	}

}


//========================================================
//
//  File Name:   main.cpp
//
//  Author: Elizabeth (Liz) Boyle
//
//  Course and Assignment:   CSCI262 Assignment 3 Evil Hangman
//
//  Description:  This is a program of a game of hangman... EVIL HANGMAN
//
//
//=========================================================
#include <iostream>
#include <string>
#include <fstream>
#include "map.h"
#include "vector.h"
#include "set.h"
#include "functions.h"

using namespace std;

int main() {
	int highestscore = 26;
	int length;
	int guesses;
	Map<int, Vector<string>> words_key;
	bool runn_total;
	int running_total = 0;
	char run_entry;
	bool playing = true;
	string used_word;
	char letter_guess;
	Set<char> guessed;
	bool correct = false;
	char again_entry;
	bool eval = false;
	cout << "Welcome to (*cough* *cough* Evil *cough*) Hangman!!" << endl;
	cout << "Loading library...please wait." << endl;

	ifstream fin("dictionary.txt");
	if (!fin) {
		cerr << "ERROR, exiting." << endl;
		return -1;
	}

	string word;
	while (!fin.eof()) {
		fin >> word;
		words_key[word.size()].add(word);
	}
	fin.close();
	
	do {
		int highscore = 0;
		/*********************/
		cout << "High Score: " << highestscore << endl;
		cout << "----------------------------" << endl;
		cout << "Enter the length of the word you would like to guess: ";
		cin >> length;
		while (length <= 0 || !words_key.containsKey(length)) { //need to find max length of words in the txt doc
			cout << endl << "Invaild input" << endl;
			cout << "Enter the length of the word you would like to guess: ";
			cin >> length;
		}

		/*********************/

		cout << "Enter the number of guesses you would like: ";
		cin >> guesses;
		while (guesses <= 0) {
			cout << endl << "You need to have at least one guess." << endl;
			cout << "Enter the number of guesses you would like: ";
			cin >> guesses;
		}

		/*********************/

		cout << "You would like a a running total of the number of words remaining in the words list? (Y/N) :";
		cin >> run_entry;
		if (run_entry == 'y' || run_entry == 'Y') {
			runn_total = true;
			running_total = words_key[length].size();
		}
		else { runn_total = false; }

		/**********************/
		guessed.clear();
		string output = Blanked(length);
		string blank = Blanked(length);
		string rev = "";
		
		cout << endl << "----------------------------" << endl;
		if (runn_total) {cout << "Words Remaining in Word List:" << running_total << endl;}
		cout << "Remaining guesses: " << guesses << endl;
		cout << "Solve: " << output << endl;
		cout << "Guess: ";
		cin >> letter_guess;
		while (Conversion(letter_guess) == false) {
			cout << "Guess: ";
			cin >> letter_guess;
		}
		guessed.add(letter_guess);
		guesses--;
		highscore++;

		Map <string, Vector<string>> new_key = First_Family_Key(words_key, length, letter_guess, rev);
		if (new_key.containsKey(blank)) {
			cout << "No, there is no " << letter_guess << " in the word." << endl;
		}
		else {
			cout << "Yes, there is a " << letter_guess << " in the word." << endl;
			Reveal(rev, output);
		}
		cout << endl << "----------------------------" << endl;
		if (runn_total) {
			running_total = new_key[rev].size();
			cout << "Words Remaining in Word List:" << running_total << endl;
		}
		cout << "Remaining guesses: " << guesses << endl;
		cout << "You have guessed: " << guessed << endl;
		cout << "Solve: " << output << endl;


		do {
			cout << "Guess: ";
			cin >> letter_guess;
			while (!Conversion(letter_guess)) {
				cout << "Guess: ";
				cin >> letter_guess;
			}
			while (guessed.contains(letter_guess)) {
				cout << endl << "You have already guessed that, try again: ";
				cin >> letter_guess;
				Conversion(letter_guess);
				while (!Conversion(letter_guess)) {
					cin >> letter_guess;
				}
			}
			guessed.add(letter_guess);
			guesses--;
			highscore++;

			new_key = Smaller_Key(new_key, letter_guess, rev);
			if (new_key.containsKey(blank)) {
				cout << "No, there is no " << letter_guess << " in the word." << endl;
			}
			else {
				cout << "Yes, there is a " << letter_guess << " in the word." << endl;
				Reveal(rev, output);
			}

			cout << endl << "----------------------------" << endl;
			if (runn_total) {
				running_total = new_key[rev].size();
				cout << "Words Remaining in Word List:" << running_total << endl;
			}
			cout << "Remaining guesses: " << guesses << endl;
			cout << "You have guessed: " << guessed << endl;
			cout << "Solve: " << output << endl;
			Win_Check(output, correct);
		} while (correct == false && guesses != 0);

		/***Check for if won or ran out of guesses***/
		if (guesses == 0 && correct == false) {
			cout << "Sorry, you ran out of guesses :(" << endl;
			cout << "The word was: " << new_key[rev][rand() % new_key[rev].size()] << endl;
		}
		else if (correct == true) {
			cout << "Congrats! You guessed it!" << endl;
			cout << "It took you: " << highscore << " guesses." << endl;
			if (highscore < highestscore) {
				highestscore = highscore;
				cout << "New High Score! " << highestscore << endl;
			}
		}
		cout << "Would you like to play again?(Y/N)";
		cin >> again_entry;
		if (again_entry == 'y' || again_entry == 'Y') {
			playing = true;
			cout << endl;
		}
		else { playing = false; }
	} while (playing == true);

	return 0;
}
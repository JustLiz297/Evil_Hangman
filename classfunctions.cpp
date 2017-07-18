//========================================================
//
//  File Name:   classfunctions.cpp
//
//  Author: Elizabeth (Liz) Boyle
//
//  Course and Assignment:   CSCI262 Assignment 3 Evil Hangman
//
//  Description:  Functions definded for Evil Hangman
//
//
//=========================================================

#include <iostream>
#include <string>
#include "map.h"
#include "functions.h"

using namespace std;

string Blanked(int length) {
	string retn;
	for (int i = 0; i < length; i++) {
		retn += ('_');
	}
	return retn;
}
void Reveal(string& word, string& output) {
	for (int i = 0; i < word.length(); i++) {
		if (output.at(i) == '_' && word.at(i) != '_') {
			output[i] = word.at(i);
		}
	}
}
void Win_Check(string& output, bool& win) {
	int counter = output.length();
	for (char a : output) {
		if (a != '_') {
			counter--;
		}
	}
	if (counter == 0) {
		win = true;
	}
}
bool Conversion(char& guess) {
	if (guess == 'A' || guess == 'a') {
		guess = 'a';
		return true;
	}
	else if (guess == 'B' || guess == 'b') {
		guess = 'b';
		return true;
	}
	else if (guess == 'C' || guess == 'c') {
		guess = 'c';
		return true;
	}
	else if (guess == 'D' || guess == 'd') {
		guess = 'd';
		return true;
	}
	else if (guess == 'E' || guess == 'e') {
		guess = 'e';
		return true;
	}
	else if (guess == 'F' || guess == 'f') {
		guess = 'f';
		return true;
	}
	else if (guess == 'G' || guess == 'g') {
		guess = 'g';
		return true;
	}
	else if (guess == 'H' || guess == 'h') {
		guess = 'h';
		return true;
	}
	else if (guess == 'I' || guess == 'i') {
		guess = 'i';
		return true;
	}
	else if (guess == 'J' || guess == 'j') {
		guess = 'j';
		return true;
	}
	else if (guess == 'K' || guess == 'k') {
		guess = 'k';
		return true;
	}
	else if (guess == 'L' || guess == 'l') {
		guess = 'l';
		return true;
	}
	else if (guess == 'M' || guess == 'm') {
		guess = 'm';
		return true;
	}
	else if (guess == 'N' || guess == 'n') {
		guess = 'n';
		return true;
	}
	else if (guess == 'O' || guess == 'o') {
		guess = 'o';
		return true;
	}
	else if (guess == 'P' || guess == 'p') {
		guess = 'p';
		return true;
	}
	else if (guess == 'Q' || guess == 'q') {
		guess = 'q';
		return true;
	}
	else if (guess == 'R' || guess == 'r') {
		guess = 'r';
		return true;
	}
	else if (guess == 'S' || guess == 's') {
		guess = 's';
		return true;
	}
	else if (guess == 'T' || guess == 't') {
		guess = 't';
		return true;
	}
	else if (guess == 'U' || guess == 'u') {
		guess = 'u';
		return true;
	}
	else if (guess == 'V' || guess == 'v') {
		guess = 'v';
		return true;
	}
	else if (guess == 'W' || guess == 'w') {
		guess = 'w';
		return true;
	}
	else if (guess == 'X' || guess == 'x') {
		guess = 'x';
		return true;
	}
	else if (guess == 'Y' || guess == 'y') {
		guess = 'y';
		return true;
	}
	else if (guess == 'Z' || guess == 'z') {
		guess = 'z';
		return true;
	}
	else {
		cout << "That is not a letter." << endl;
		return false;
	}
}
Map <string, Vector<string>> First_Family_Key(Map<int, Vector<string>>& length_key, int& length, char& guess, string& rev) {
	Map<string, Vector<string>> new_key;
	Vector<string> words_list;
	Vector<string> valid_words = length_key.get(length);
	/***Converting to New Map***/
	for (string s : valid_words) {
		string word_key = "";
		for (int j = 0; j < s.size(); ++j) {
			if (guess != s.at(j)) {
				word_key += '_';
			}
			else {
				word_key += guess;
			}
		}
		new_key[word_key].add(s);
	}
	/***Choosing Key with Largest Word Count***/
	int max_length = 0;
	string max_key;
	for (string key : new_key) {
		if (new_key[key].size() > max_length) {
			max_length = new_key[key].size();
			max_key = key;
		}
	}
	/***Clearing Rest of Map except Key with Largest Word Count***/
	words_list = new_key[max_key];
	new_key.clear();
	new_key.put(max_key,words_list);
	rev = max_key;
	return new_key;
}
Map <string, Vector<string>> Smaller_Key(Map<string, Vector<string>> key, char& guess, string& rev) {
	Map<string, Vector<string>> new_key;
	Vector<string> words_list;
	Vector<string> valid_words = key.get(rev);
	/***Converting to New Map***/
	for (string s : valid_words) {
		string word_key = "";
		for (int j = 0; j < s.size(); ++j) {
			if (guess != s.at(j)) {
				word_key += '_';
			}
			else {
				word_key += guess;
			}
		}
		new_key[word_key].add(s);
	}
	/***Choosing Key with Largest Word Count***/
	int max_length = 0;
	string max_key;
	for (string key : new_key) {
		if (new_key[key].size() > max_length) {
			max_length = new_key[key].size();
			max_key = key;
		}
	}
	/***Clearing Rest of Map except Key with Largest Word Count***/
	words_list = new_key[max_key];
	new_key.clear();
	new_key.put(max_key, words_list);
	rev = max_key;
	return new_key;
}
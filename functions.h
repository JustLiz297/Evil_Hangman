//========================================================
//
//  File Name:  functions.h
//
//  Author: Elizabeth (Liz) Boyle
//
//  Course and Assignment:   CSCI262 Assignment 3 Evil Hangman
//
//  Description:  Functions for Evil Hangman
//
//
//=========================================================
#pragma once

#include <iostream>
#include <string>
#include "map.h"
#include "vector.h"

using namespace std;

string Blanked(int length);
void Reveal(string& word, string& output);
bool Conversion(char& guess);
void Win_Check(string& output, bool& win);
Map <string, Vector<string>> First_Family_Key(Map<int, Vector<string>>& length_key, int& length, char& guess, string& rev);
Map <string, Vector<string>> Smaller_Key(Map<string, Vector<string>> key, char& guess, string& rev);



/*	Assignment 1B
 *	Title: Easier Done Than Said
 *	Authors: Andrew Montenigro, Jessica Neal, Nate Richards 
 */


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool isVowel(char);
bool containsVowel(string);
bool containsNoConsecutiveTypes(string);
bool containsNoConsecutiveChars(string);

int main() {
	ifstream infile;
	ofstream outfile;
	infile.open("say.in");
	outfile.open("say.out");
	string input = "";
	infile >> input;

	while(input != "end"){
		if(!containsVowel(input) || !containsNoConsecutiveTypes(input) || !containsNoConsecutiveChars(input))
		{
			printf("<%s> is not acceptable.\n",input.c_str());
			outfile << '<' << input << "> is not acceptable" << endl;
		}
		else{
			printf("<%s> is acceptable.\n",input.c_str());
			outfile << '<' << input << "> is acceptable" << endl;
		}
		infile >> input;
	}
	outfile.close();
	return 0;
}	//main

bool isVowel(char c){
	string test = "AEIOUaeiou";				//contains both cases to make code reuse easy
	if(test.find(c) == -1) return false;	//string::find() returns value -1 if char is NOT in string
	return true;
}	//isVowel

bool containsVowel(string s){
	for(int i = 0; i < s.length();i++){
		if(isVowel(s[i])) return true;
	}
	return false;
}	//containsVowel

bool containsNoConsecutiveTypes(string input){
	for(int i = 2; i < input.length(); i++){	//use 3rd char in input as a start point
		if( isVowel(input[i]) && isVowel(input[i-1]) && isVowel(input[i-2]) ) return false;
		if( !isVowel(input[i]) && !isVowel(input[i-1]) && !isVowel(input[i-2]) ) return false;
	}
	return true;
}

bool containsNoConsecutiveChars(string input){
	char previous,current;
	previous = input[0];
	for(int i = 1; i < input.length(); i++)
	{
		current = input[i];
		if( ((current == 'e')&&(previous == 'e')) || ((current == 'o')&&(previous == 'o')) )
		{	//accounts for 'ee' and 'oo'
			previous = current;
			continue;
		}
		if(current == previous) return false;
		previous = current;
	}
	return true;
}


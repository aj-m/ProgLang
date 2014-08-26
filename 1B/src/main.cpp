#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool isVowel(char);
bool containsVowel(string);
bool containsNoConsecutiveTypes(string);
bool containsNoConsecutiveChars(string);

int main() {
	fstream infile;
	infile.open("say.in");
	//infile.open("say.txt");
	//Spec says say.in
	string input = "";
	//int elementCount = 0;
	infile >> input;
	while(input != "end"){
		
	}
	
		
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
	
}

bool containsNoConsecutiveChars(string input){
	
}

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool isVowel(char);
bool containsVowel(string);


int main() {
	fstream infile;
	infile.open("say.in");
	//infile.open("say.txt");
	//Spec says say.in
	string input = "";
	infile >> input;
	while(input != "end"){
		cout << input << endl;
		infile >> input;
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

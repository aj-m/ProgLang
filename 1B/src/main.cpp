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
	//infile.open("say.txt");
	//Spec says say.in
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
	int consecVow,consecCon = 0;	//accumulators
	
	for(int i = 0; i < input.length(); i++){
		if(consecVow > 0 && consecCon > 0)
		{
			consecVow = 0;
			consecCon = 0;
			if(isVowel(input[i])) consecVow++;
			else consecCon++;
		}
		else
		{
			if(isVowel(input[i])) consecVow++;
			else consecCon++;
		}
	}
	if(consecVow >= 3 || consecCon >= 3) return false;
	else return true;
}

bool containsNoConsecutiveChars(string input){
	char previous,current;
	previous = input[0];
	for(int i = 1; i < input.length(); i++)
	{
		current = input[i];
		if( ((current == 'e')&&(previous == 'e')) || ((current == 'o')&&(previous == 'o')) )
		{
			previous = current;
			continue;
		}
		if(current == previous) return false;
		previous = current;
	}
	return true;
}

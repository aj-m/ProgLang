#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool isVowel(char);

int main() {
	
	return 0;
}

bool isVowel(char c){
	string test = "AEIOUaeiou";
	if(test.find(c) == -1) return false;
	else return true;
}

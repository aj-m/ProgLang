/*
 *	Title: Loansome Car Buyer
 *	Authors: Andrew Montenigro, Jessica Neal, Nate Richards
 */



#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main() {
	ifstream infile;
	ofstream outfile;
	int loanDuration, depreciationRecords;
	float downPayment, loanAmount, depreciationPercentage, currentValue, initialValue, aggregateDepreciation = 0.f;
	
	infile.open("loan.in");
	outfile.open("loan.out");
	infile >> loanDuration;
	infile >> downPayment;
	infile >> loanAmount;
	infile >> depreciationRecords;
	cout << loanDuration << endl;
	cout << downPayment << endl;
	cout << loanAmount << endl;
	cout << depreciationRecords << endl;
	
	return 0;
}


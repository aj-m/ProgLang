/*
 *	Title: Loansome Car Buyer
 *	Authors: Andrew Montenigro, Jessica Neal, Nate Richards
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void getLoan(/*input*/ifstream&, /*outputs*/int&, float&, float&, int&);	//Passed by reference for multiple outputs
void getRecord(ifstream&, int&, float&);

int main() {
	ifstream infile;
	ofstream outfile;
	int loanDuration, recordCount, loanMonth;
	float downPayment, monthlyPayment, loanAmountOwed, depreciationPercentage;
	float currentValue, initialValue;
	float aggregateDepreciation = 0.f;
	infile.open("loan.in");
	outfile.open("loan.out");
	//Start execution	
	while(infile.good()){
		getLoan(infile, loanDuration, downPayment, loanAmountOwed, recordCount);
		if(loanDuration < 0) break;		//Signals end of input
		initialValue = downPayment+loanAmountOwed;
		monthlyPayment = loanAmountOwed/(float)loanDuration;
		float currentPercentage;
		int previousMonth = 0;
		for(int i = 0; i < recordCount; i++){
			getRecord(infile, loanMonth, depreciationPercentage)
			if(loanMonth == (previousMonth+1))
			{
				currentPercentage = depreciationPercentage;
				currentValue = initialValue - (float)(loanMonth)*currentPercentage;
				loanAmountOwed -= monthlyPayment;
			}
			else
			{
				loanAmountOwed -= (float)(loanMonth - previousMonth)*(monthlyPayment);
				currentValue = initialValue - (float)(loanMonth - previousMonth)*(currentPercentage);
			}
			
		
		}
		
		
		//infile >> loanDuration >> downPayment >> loanAmountOwed >> recordCount;
		//cout << loanDuration << endl << downPayment << endl << loanAmountOwed << endl << recordCount << endl;	
	}
	outfile.close()
	
	return 0;
}	//main

void getLoan(ifstream& infile, int& duration, float& down, float& amount, int& records){
	infile >> duration >> down >> amount >> records;
}	//getLoan

void getRecord(ifstream& infile, int& month, float& percentage){
	infile >> month >> percentage;
}	//getRecord

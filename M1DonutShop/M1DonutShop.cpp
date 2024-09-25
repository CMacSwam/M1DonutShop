/*
* Author: Chase McCluskey
* Date: 10/3/24
* 
* Description
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	string variety1 = "regular";
	string variety2 = "Fancy";
	int regularprice = 75;
	int regulardozenprice = 799;
	int fancyprice = 85;
	int fancydozenprice = 849;
	int applefritterprice = 150;
	double salestax = .075;
	int quarter = 25;
	int dime = 10;
	int nickel = 5;
	int penny = 1;
	int dollar = 100;
	int dollarcount = 0;
	int quartercount = 0;
	int dimecount = 0;
	int nickelcount = 0;
	int pennycount = 0;
	double totalprice = 0;
	int regulardozen = 0;
	int fancydozen = 0;

	//Program execute once per customer 
	//ask for the number of regular donuts, fancy donuts, and apple fritters
	int regulardonuts = 0;
	cout << "Number of regular donuts order: ";
	cin >> regulardonuts;
	int fancydonuts = 0;
	cout << "Number of fancy donuts ordered: ";
	cin >> fancydonuts;
	int applefritters = 0;
	cout << "Numer of apple fritters ordered: ";
	cin >> applefritters;

	//To calculate cost, determine the number of donuts in terms of dozens
	//any donuts left over are priced individually 
	//the cost must include sales tax
	if (regulardonuts >= 12) {
		regulardozen /= 12;
		regulardonuts = regulardonuts - (12 * regulardozen); 
		totalprice = totalprice + (regulardozen * regulardozenprice) + (regularprice * regulardonuts);
	}
	if (fancydonuts >= 12) {
		fancydozen /= 12;
		fancydonuts = fancydonuts - (12 * fancydozen);
	}
	totalprice = totalprice + (fancydozenprice * fancydozen) + (fancydonuts * fancyprice);
	totalprice = totalprice + (regulardozen * regulardozenprice) + (regularprice * regulardonuts);
	totalprice = totalprice + (applefritters * applefritterprice);
	totalprice = (double) totalprice + (double)(totalprice * salestax);
	cout << "Customers Owes $" << setprecision(3) << totalprice / 100 << endl;
	//After displaying the cost
	//obtain amount of payment recieved 
	cout << "Customer Pays: $";
	double payment = 0;
	cin >> payment;
	//calculate change provided to the customer 
	if (payment == (totalprice / 100)) {
		cout << "Exact payment recieved - no change owed.";
	}
	else {
		cout << "Change owed is $" << payment - (totalprice / 100) << " - ";
	}
	double cashback = (payment * 100) - (double)totalprice + 1;
	
		while (cashback >= 100) {
			cashback -= dollar;
			dollarcount++;
		}
		while (cashback >= 25){
			cashback -= quarter;
			quartercount++;
		}
		while (cashback >= 10){
			cashback -= dime;
			dimecount++;
		}
		while (cashback >= 5) {
			cashback -= nickel;
			nickelcount++;
		}
		while (cashback >= 1) {
			cashback -= penny;
			pennycount++;
		}

	if (dollarcount == 1) {
		cout << " - " << dollarcount << " dollar";
	}
	else if (dollarcount > 1){
		cout << ", " << dollarcount << " dollars";
	}
	if (quartercount == 1) {
		cout << ", " << quartercount << " quarter";
	}
	else if (quartercount > 0){
		cout << ", " << quartercount << " quarters";
	}
	if (dimecount == 1) {
		cout << ", " << dimecount << " dime";
	}
	else if (dimecount > 1){
		cout << ", " << dimecount << " dimes";
	}
	if (nickelcount == 1) {
		cout << ", " << nickelcount << " nickel";
	}
	else if (nickelcount > 1){
		cout << ", " << nickelcount << " nickels";
	}
	if (pennycount == 1){
		cout << ", " << pennycount << " penny";
	}
	else if (pennycount > 1) {
		cout << ", " << pennycount << " pennies";
	}
	cout << ".";
}

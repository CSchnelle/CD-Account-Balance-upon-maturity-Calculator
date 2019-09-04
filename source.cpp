#include "stdafx.h"
#include <iostream>
using namespace std;
class CDAccount
{
public:
    CDAccount();
    CDAccount(double new_balance, double new_interest_rate, int new_term);
    double get_initial_balance() const;
    double get_balance_at_maturity() const;
    double get_interest_rate() const;
    int get_term() const;
    void input(istream& in);
    void output(ostream& out);

private:
    int dollar;
    int cent;
    double interest_rate;
    int term; // months until maturity
};

int main()
{
    CDAccount account;
    cout << "Test Menu: " << endl; //output
    account.output(cout);
    cout << "Enter balance, rate and term: (Press Enter Key after each entry)"; //prompts user to input data
    account.input(cin);
    account.output(cout);
}

CDAccount::CDAccount() {
    dollar = 0;
    cent = 0;
    interest_rate = 0;
    term = 0;
}
CDAccount::CDAccount(double new_balance, double new_interest_rate, int new_term) { //balance and interest rate are double variables
    dollar = (int)new_balance;
    cent = (new_balance - dollar) * 100;
    interest_rate = new_interest_rate;
    term = new_term;
}

double CDAccount::get_initial_balance() const {
    return dollar + (double)cent / 100;
}

double CDAccount::get_balance_at_maturity() const {
    double balance = dollar + (double)cent / 100; //this makes sure that the balance as a whole is an accumulation of dollars and cents
    double amount = balance * pow(1 + interest_rate / 12, term);
    return amount;
}

double CDAccount::get_interest_rate() const {
    return interest_rate;
}

int CDAccount::get_term() const {
    return term;
}

void CDAccount::output(ostream& out) { //this is the output menu, this displays the results retrieving the data from the input menu
    out << "Balance:" << get_initial_balance() << endl;
    out << "Interest rate: " << get_interest_rate() * 100 << "%" << endl; //interest rate is double type percentage
    out << "Term: " << term << " months" << endl; // term is int type in term of months out of 12 possible months
    out << "Balance at maturity:" << get_balance_at_maturity() << endl; //this is the balance of the account once it has accumulated the interest set by rate and by how many months
}

void CDAccount::input(istream& in)
{
    double balance;
    in >> balance; // get initial balance from user

                   // convert balance to dollars and cents since this is how balance stored
    dollar = (int)balance; // dollar is the interger part of balace
    cent = (int)((balance - dollar) * 100); // cent is the fraction part * 100

    in >> interest_rate; // get interest rate from user
    in >> term; // get term from user
}

/*OUTPUT
Test Menu:
Balance:0
    Interest rate : 0 %
    Term : 0 months
    Balance at maturity : 0
    Enter balance, rate and term : (Press Enter Key after each entry)200.00
    6.0
    12
    Balance : 200
    Interest rate : 600 %
    Term : 12 months
    Balance at maturity : 25949.3
    Press any key to continue . . .
    */
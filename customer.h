//Programmer: Ryan Vasquez
//Nov 12, 2013
//Class: CS53 Section F
//Purpose: Simulate a business
#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include "product.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MAXNUMBERPURCH = 20;


class customer
{
  private:
    product m_proditems[MAXNUMBERPURCH];
    short m_numpurchases;
    float m_money;
    string m_name;
  public:
    customer();
    //Description: This is the default constructor for a customer object
    //Pre: none
    //Post: It will give the customer a random amount of money from 4-250
    //It will make thier name blank, set number of purcheses to 0
    customer(string name, float money);
    //Description: This is another constructor, you can set the customers name
    //and set thier initial amount of money.
    //Pre:
    //Post: It will set thier m_numpurchases to 0
    bool purchase(string item);
    //Description: this let the customer purchase and item
    //Pre: pass a string
    //Post: It will at 1 to the m_numpurchases and put the item into
    //the string array.
    string get_custname();
    //Description: This is an accessor function that returns the customers name
    //Pre:none
    //Post: returns the customers name as a string
    float get_money();
    //Description: This is an accessor function that returns the money that the
    //customer has.
    //Pre: none
    //Post: This returns the money the customer has as a string.
    void change_money(float money);
    //Description: This a mutator function that lets the programmer change the
    //amount of money a customer has
    //Pre: none
    //Post: The m_money variable will be set to the money variable that is
    //passed into the function.
    void print();
    //Description: This is a print function that will print out the information
    //about the customer
    //Pre: none
    //Post: The function will output the customers name, the amount of money
    //they have, and a list of the items they have purchased
};



#endif // CUSTOMER_H_INCLUDED

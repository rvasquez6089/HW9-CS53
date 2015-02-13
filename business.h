//Programmer: Ryan Vasquez
//Nov 12, 2013
//Class: CS53 Section F
//Purpose: Simulate a business
#ifndef BUSINESS_H_INCLUDED
#define BUSINESS_H_INCLUDED
#include "customer.h"
#include <fstream>
using namespace std;
const short NUMOPRODUCTS = 10;
const short NUMOCUSTOMERS = 10;
const string INVENTORYFILE = "inventory.txt";
const float FIXEDPRICE = 40.00;
class business
{
  private:
    short m_numoproducts;//The current number of different products in inventory
    short m_numocustomers;//Number of customers in the store
    string m_name;//Name of the business
    float m_moneyinreg;
    string items[NUMOPRODUCTS];
    customer people[NUMOCUSTOMERS];
  public:
    business();
    //Description: The default constructor sets the m_money in reg to 0
    //and sets the m_numoproducts to 0 and the m_numocustomers to 0.
    business(string name, float money);
    //Descrpition: constructor. Pass in a string name and the starting amount
    //of money in the register
    //Pre: The name must be a string, the money must be a float
    void print();
    //Description: The print function will print out the business information
    //Pre: None
    //Post: This will print out the business name
    //The name of customers
    //The items in the inventory
    //and the money currently in the cash register
    void check_stream(ifstream& in);
    //Description: the check_stream function checks if the ifstream is valid
    //Pre: only an ifstream can be passed in
    //Post: if the ifstream is invalid it will ask the user
    //for a filename to open so that the program can continue
    void newcustomer(customer& newp);
    //Description: the newcustomer function adds a new customer to the business
    //Pre: The passed parameter must be a customer object
    //Post: It will add a new customer to the customer object array
    //The function will also output the customers name and money
    void make_a_sale();
    //Description: the make_a_sale function will force all of the customers
    //to make a $40 purchase of a random item from the inventory.
    //It will output the name of the purchaser, the object they have purchased
    //and the amount of money they had after they make the purchase.
    //Pre: There must be customers in the store who have money and there must
    //items in the inventory.
    //Post: It will add $40 to the register and subtract $40 from the users
    //money.
};

#endif // BUSINESS_H_INCLUDED

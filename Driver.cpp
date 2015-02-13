//Programmer: Ryan Vasquez
//Nov 12, 2013
//Class: CS53 Section F
//Purpose: Simulate a business
#include <iostream>
#include "customer.h"
#include "business.h"
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    customer Ryan("Ryan", 150.00);
    customer Burgess("Burgess", 50.00);
    customer Chao("Chao", 80.00);
    business Kroger("Kroger", 5000.00);
    Kroger.newcustomer(Ryan);
    Kroger.newcustomer(Burgess);
    Kroger.newcustomer(Chao);
    Kroger.make_a_sale();
    Kroger.make_a_sale();
    Kroger.make_a_sale();
    Kroger.print();
    return 0;
}

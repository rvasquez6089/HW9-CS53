//Programmer: Ryan Vasquez
//Nov 12, 2013
//Class: CS53 Section F
//Purpose: Simulate a business
#include "business.h"
#include <cstring>
using namespace std;

business::business()
{
  m_moneyinreg = 0;
  m_numoproducts = 0;
  m_numocustomers = 0;
  m_name = "";
}

business::business(string name, float money)
{
  m_name = name;
  m_moneyinreg = money;
  m_numocustomers = 0;
  m_numoproducts = 0;
  ifstream in;
  in.open(INVENTORYFILE.c_str());
  check_stream(in);
  for(int i = 0; ((i < NUMOPRODUCTS) &&!(in.eof())); i++)
  {
    getline(in,items[i]);
    m_numoproducts++;
  }
  m_numoproducts = m_numoproducts - 1;
  in.close();
}

void business::print()
{
  cout<<"\n-------------------Store info-------------------\n";
  cout<<"\n\n----------------------------------------------\n";
  cout<<"                "<<m_name<<"      "<<endl;
  cout<<"__________________________________________"<<endl;
  cout<<"|Customers:                              "<<endl;
  for(int i = 0; i < m_numocustomers; i++)
  {
    cout<<"| Customer #"<<i<<". "<<people[i].get_custname()<<endl;
    people[i].print();
  }
  cout<<"|__________________________________________"<<endl;
  cout<<"|Inventory:"<<endl;
  for(int i = 0; i < m_numoproducts; i++)
  {
    cout<<"|Item #"<<i<<". "<<items[i]<<endl;
  }
  cout<<"|__________________________________________"<<endl;
  cout<<"|Cashregister Balance: $"<<m_moneyinreg<<endl;

}

void business::newcustomer(customer& newp)
{
  people[m_numocustomers] = newp;
  cout<<"\n---------------------------  ---------------\n";
  cout<<"A new customer has entered the store!"<<endl;
  cout<<"Name: "<<newp.get_custname()<<endl;
  cout<<"Money: $"<<newp.get_money()<<endl;
  m_numocustomers++;
}

void business::make_a_sale()
{
  int productnum = 0;
  float currentbal = 0;
  float newbal = 0;
  for(int i = 0; i < m_numocustomers; i++)
  {
    if(people[i].get_money() >= FIXEDPRICE)
    {
      productnum = rand()%m_numoproducts;
      if(people[i].purchase(items[productnum]))
      {
        currentbal = people[i].get_money();
        newbal = currentbal - FIXEDPRICE;
        m_moneyinreg = m_moneyinreg + FIXEDPRICE;
        people[i].change_money(newbal);
        cout<<"\n----------------------------------------------------"<<endl;
        cout<<"The customer "<<people[i].get_custname()<<" has purchased";
        cout<<"item #"<<productnum<<" "<<items[productnum]<<endl;
        cout<<people[i].get_custname();
        cout<<"'s new balance is $"<<people[i].get_money()<<endl;
      }
      else
      {
        cout<<"This purchase has failed"<<endl;
        cout<<"Check the customer purchase function"<<endl;
      }
    }
    else
    {
      cout<<"Customer #"<<i<<" "<<people[i].get_custname()<<" does not ";
      cout<<"have enough money to buy anything"<<endl;
    }
  }

}

void business::check_stream(ifstream& in)
{
  while(!(in.good()))
  {
    char filename[50];
    cout<<"Please enter the name of file you are trying to open";
    cin>>filename;
    in.open(filename);
  }
}

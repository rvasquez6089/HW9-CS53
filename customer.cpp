//Programmer: Ryan Vasquez
//Nov 12, 2013
//Class: CS53 Section F
//Purpose: Simulate a business
#include "customer.h"


customer::customer()
{
  for(int i = 0; i<MAXNUMBERPURCH; i++)
  {
    m_proditems[i].m_proname = "";
  }
  m_name = "";
  srand(time(NULL));
  m_money = rand()%251+4;
  m_numpurchases = 0;
}

customer::customer(string name, float money)
{
  m_name = name;
  m_money = money;
  m_numpurchases = 0;
}

bool customer::purchase(string item)
{
  m_proditems[m_numpurchases].m_proname = item;
  if(m_proditems[m_numpurchases].m_proname == item)
  {
    m_numpurchases++;
    return 1;
  }
  else
  {
    return 0;
  }
}

string customer::get_custname()
{
  return m_name;
}

float customer::get_money()
{
  return m_money;
}

void customer::change_money(float money)
{
  m_money = money;
}

void customer::print()
{
  int j = 0;
  cout<<"| "<<m_name<<" has $"<<m_money<<" and purchased item(s) ";
  for(int i = 0; i < m_numpurchases; i++)
  {

    cout<<m_proditems[i].m_proname<<", ";
    while(j > 5)
    {
      cout<<"\n|";
      j = 0;
    }
    j++;
  }
  cout<<endl;
}

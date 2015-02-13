//Programmer: Ryan Vasquez
//Date, November 4th, 2013
//Class: CS53 section f
//Description: This is cpp that contains all of the function for the
//wordfunctions.h file.
#include "wordfunctions.h"

void get_oneword(char word[], ifstream& in)
{
  int checkrun = 0;
  int lastchar = 0;
  int j = 0;
  int i = 0;
  do
  {
    word[i] = in.get();
    checkrun = 1;
  }while((i < SIZE)&&(word[i])==' ');
  if(!(in.peek()==' '))
  {
    do
    {
      word[j+checkrun] = in.get();
      lastchar++;
      j++;
    }while((j < SIZE)&&(!(in.peek()==' '||
        in.peek() =='.'||in.peek()==','||
                    in.peek()=='\n')||in.peek() == 255));
  }
  word[lastchar+1] = '\0';
}


void getmainword(char mainobj[], char secondobj[], ifstream& in)
{
  char cmpword[SIZE] = "The";
  char cmpword2[SIZE] = "the";
  bool firstcheck = 1;
  bool secondcheck = 1;
  for (int i = 0; i<SIZE&&firstcheck == 1; i++)
  {
    get_oneword(mainobj, in);
    if(!(strcmp(mainobj, cmpword)))
    {
      get_oneword(mainobj, in); //gets the word following The
      firstcheck = 0;
    }
  }
  for (int i = 0; i<SIZE&&secondcheck == 1; i++)
  {
    get_oneword(secondobj, in);
    if(!(strcmp(secondobj, cmpword2)))
    {
      get_oneword(secondobj, in); //gets the word following The
      secondcheck = 0;
    }
  }
  get_oneword(cmpword, in);
  in.get();
  in.get();
}

void get_new_subjects(char subject1[], char subject2[])
{
  ifstream in;
  int list1length = 0;
  int list1choice = 0;
  int list2length = 0;
  int list2choice = 0;
  in.open(FILELIST1);
  check_stream(in);
  do
  {
    in.getline(subject1, SIZE);
    list1length++;
  }while(!(in.eof()));
  in.close();
  list1choice = rand()%list1length;
  in.open(FILELIST1);
  for(int i = 0; i<(list1choice); i++)
  {
    in.getline(subject1, SIZE);
  }
  in.close();
  makenullterm(subject1);
  in.open(FILELIST2);
  check_stream(in);
  do
  {
    in.getline(subject2, SIZE);
    list2length++;
  }while(!(in.eof()));
  in.close();
  list2choice = rand()%list2length;
  in.open(FILELIST2);
  for(int i = 0; i<(list2choice); i++)
  {
    in.getline(subject2, SIZE);
  }
  in.close();
  makenullterm(subject2);
}


void makenullterm(char cstring[])
{
  bool fixed = 0;
  bool checked = 0;
  char charcmp;
  for(int i = 0; (i<SIZE&&!(fixed)); i++)
  {
    checked = 0;
    for(int j = 33; j<126&&(!checked); j++)
    {
      charcmp = j;
      if(cstring[i] == charcmp)
      {
        checked = 1;
      }
    }
    if(!(!(checked == 0) || cstring[i] == ' '))
    {
      cstring[i] = '\0';
      fixed = 1;
    }
  }
}

void makenullterm(char cstring[], bool longg)
{
  bool fixed = 0;
  bool checked = 0;
  char charcmp;
  for(int i = 0; (i<SIZE&&!(fixed)); i++)
  {
    checked = 0;
    for(int j = 0; j<126&&(!checked); j++)
    {
      charcmp = j;
      if(cstring[i] == charcmp)
      {
        checked = 1;
      }
    }
    if(!(!(checked == 0) || cstring[i] == ' '))
    {
      cstring[i] = ' ';
      fixed = 1;
    }
  }
}

void output_title(char newchar1[], char newchar2[], ofstream& out)
{
  static int fablenum = 1;
  out<<"Moe Fable #"<<fablenum<<": ";
  out<<"The "<<newchar1<<" and the "<<newchar2<<" fable.";
  fablenum++;
}

void get_moe_rant(char rant[])
{
  ifstream in;
  in.open(RANTFILE);
  check_stream(in);
  int list1length = 0;
  int list1choice = 0;
  do
  {
    in.getline(rant, BIGSIZE, '\r');
    list1length++;
  }while(!(in.eof()));
  in.close();
  list1choice = rand()%list1length;
  in.open(RANTFILE);
  for(int i = 0; i<(list1choice); i++)
  {
    in.getline(rant, BIGSIZE, '\r');
    makenullterm(rant, 0);
  }
  in.close();
}

void output_rant(char rant[], ofstream& out)
{
  out<<rant;
}

void get_moral(char moral[])
{
  ifstream in;
  in.open(MORALS);
  check_stream(in);
  int list1length = 0;
  int list1choice = 0;
  do
  {
    in.getline(moral, BIGSIZE, '\r');
    list1length++;
  }while(!(in.eof()));
  in.close();
  list1choice = rand()%list1length;
  in.open(MORALS);
  for(int i = 0; i<(list1choice); i++)
  {
    in.getline(moral, BIGSIZE, '\r');
    makenullterm(moral, 0);
  }
  in.close();
}

void output_moral(char moral[], ofstream& out)
{
  out<<"The Moe-rale of this story is: "<<moral<<"\n";
}

void output_newstory(char originalchar1[], char originalchar2[],
        char newchar1[], char newchar2[], ofstream& out, ifstream& in)
{
  char transfer_word[BIGSIZE] = {'\0'};
  char transfer_punct;
  char rant[BIGSIZE];
  int randnum = 0 ;

  do
  {
    while(((in.peek()==' '||
      in.peek() =='.'||in.peek()==',')||
                  in.peek()=='\n'))
    {
      in.get(transfer_punct);
      out<<transfer_punct;
      if(transfer_punct == '.')
      {
        randnum = rand()%4;
        if(randnum == 1)
        {
          get_moe_rant(rant);
          out<<" "<<rant<<endl;
        }
      }
    }
    get_oneword(transfer_word, in);
    if(!(strcmp(transfer_word, originalchar1)))
    {
      strcpy(transfer_word, newchar1);

    }
    else if(!(strcmp(transfer_word, originalchar2)))
    {
      strcpy(transfer_word, newchar2);
    }
    makenullterm(transfer_word);
    out<<""<<transfer_word;
    for(int i = 0; i <BIGSIZE; i++)
    {
      transfer_word[i] = '\0';
    }
  }while(!(in.eof()));
}

void check_stream(ifstream& in)
{
  while(!(in.good()))
  {
    char filename[SIZE];
    cout<<"Please enter the name of file you are trying to open";
    cin>>filename;
    in.open(filename);
  }
}


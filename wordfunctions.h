//Programmer: Ryan Vasquez
//Date, November 4th, 2013
//Class: CS53 section f
//Description: This wordfunctions.h file that has all of the constants for the
//program.
#ifndef WORDFUNCTIONS_INCLUDED
#define WORDFUNCTIONS_INCLUDED
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;
const int SIZE = 40; //size of NTCA's in this program
const int BIGSIZE = 200;
const char FILELIST1[SIZE] = "list1.txt";
const char FILELIST2[SIZE] = "list2.txt";
const string FABLE[5] ={"fable1.txt", "fable2.txt", "fable3.txt",
    "fable4.txt", "fable5.txt"};
const char RANTFILE[SIZE] = "Moe-rants.txt";
const char MORALS[SIZE] = "Moe-rals.txt";
const char FILEOUTPUT[SIZE] = "Newfables.txt";
void get_oneword(char word[], ifstream& in);
//Description:The getone word function will get the next word in a stream
//wthout disrupting the anything after the word including punctuations and
//spaces. The function will also take in and discard of leading white spaces
//before the next word.
//Pre: The the input file stream passed to the function must be good
//Post: the next word in the stream is put into the word NTCA.
void getmainword(char mainobj[], char secondobj[], ifstream& in);
//Description: The getmainword function will get the two main characters
//from an original fable.
//Pre: the input must verified, the subjects must both be in the first
//sentence and they must be followed by the word the word "the"
//Post:The original main characters are assigned to the mainobj
// and second obj ntcas
void get_new_subjects(char subject1[], char subject2[]);
//Description: The get new subjects function will get the two new subjects
//from list1.txt and list2.txt and assign them to subject1 and subject2
//Pre: List1.txt/list2.txt must exist
//Post: subject1 and subject2 will have two new characters in them
void makenullterm(char cstring[]);
//Description: The make null term character will clean up the NTCA sent to it
//Its purpose to get rid of new lines and stray escape squences and characters
//with in the ntca so that the ntca will look correct when it is output and it
//will add a null character if needed.
//Pre: none
//Post: cstring[] will be a nice clean NTCA
void output_title(char newchar1[], char newchar2[], ofstream& out);
//Description: The output_title function outputs outputs the title of the
//fable that moe has created
//Pre: newchar1 and newchar2 must have values in them genereated from the
//get new subjects function
//Post: The title is output to the ofstream passed to it.
void get_moe_rant(char rant[]);
//Description: The get moe rant function will a random selected rant from the
//rant.txt file and pass it to the rant array.
//Pre: CAUTION, the size of the array must be atleast of size 200
//it will carry an entire sentence!
//Post: A rant will be assigned to the rant ntca
void output_rant(char rant[], ofstream& out);
//Description: THe outputrant function will output a rant to the ofstream
//passed to it.
//Pre: the ofstream must be good
//Post: a rant will output to the out stream.
void get_moral(char moral[]);
//Description: The get moral function will get a moral from the morals.txt
//file.
//Pre: The morals file must only have one moral per line and the moral[]
//ntca passed to it must be atleast of size 200 because a whole sentence will
//be passsed to it.
//Post: A moral is assigned to moral[]
void output_moral(char moral[], ofstream& out);
//Description: THe output moral funciton will output a moral to the ofstream
//passed to it.
//Pre: the ofstream passed must be good.
//Post: the moral is put in the ofstream into the file.
void output_newstory(char originalchar1[], char originalchar2[],
        char newchar1[], char newchar2[], ofstream& out, ifstream& in);
//Description:The output new story function will takin the stream
//from the original story and copy it word for word and check
//for the sunjects that need to be replaced, it will aslo copy punctuation
//and it will will insert a rant after every senetence with a probability of
//one in four.
//Pre: the ifstream and ofstream must be connected and good, all of the ntcas
//must have values and be null terminated.
//Post: A new story will be written to the ofstream.
void check_stream(ifstream& in);
//Description: the checkstream function will check if stream is good and
//connected, if it is not will ask the user to specify a new file.
//Pre: none
//Post: none
#endif // WORDFUNCTIONS_INCLUDED

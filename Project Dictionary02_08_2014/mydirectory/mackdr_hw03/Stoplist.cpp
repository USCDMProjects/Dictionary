/******************************************************************************
Modified by: Domonick R. Mack
CSCE 240 Spring 2014
18 February 2014

Objective:
In the Stoplist.cpp file the program will read the words within the text file
that will be considered as a 'stopword'using the Scanner class that is located 
in the Utilities folder. Then it will use the tenplate class 'set<>' and an 
iterator to see if the word that is passed is a 'stopword'. Then finally the
results are then printed out and "PRESTO !!!" their is your stoplist.
******************************************************************************/

#include "Stoplist.h"

Stoplist::Stoplist()
{
}

Stoplist::~Stoplist()
{
}

/******************************************************************************
 This function will iterate through the set container. The iterator 'poop' will
 represent the begininng of the current 'theStoplist'. Until the iterator goes 
 through the 'theStoplist' set container it will run an inner if statement that
 if the iterator at its current position is equal to the word (value), which is 
 located in the Index class, then the function will return true if it is in 
 the 'Stoplist' or false if its not. 
******************************************************************************/
bool Stoplist::isInStoplist(string word)
{
  set<string>::iterator poop;
   for(poop = this->theStoplist.begin(); 
       poop != this->theStoplist.end(); ++poop){
         if(*poop == word){
             return true;
         }   
    }
    return false;
}

/******************************************************************************
 This function reads in the words to create a stoplist. Each word thats found
 to be a stopword is then inserted in to 'theStoplist' set container.
******************************************************************************/
void Stoplist::readData(Scanner& stoplistScanner)
{
   while(stoplistScanner.hasMoreData())
  {
    string wordDM = stoplistScanner.next();
    theStoplist.insert(wordDM);
  } 
}

/******************************************************************************
 This function prints out string value iterator using a for loop to goes through
 from beginning to the end of the set container (i.e. theStoplist). Then it uses
 the a string variable to concatenate the string iterator and a new line string.
******************************************************************************/
string Stoplist::toString()
{
  string returnValue;
   set<string>::iterator iter;
   for(iter = this->theStoplist.begin(); iter != 
       this->theStoplist.end(); ++iter)
  {
    returnValue += (*iter) + "\n";
  }
 return returnValue;
}

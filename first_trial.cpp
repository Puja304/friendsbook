#include "Profile.cpp"
#include "MyADT.cpp"
#include <iostream>
using namespace std;


int main(void) {

    /*
    
    Profile * elements[26];             
    unsigned int elementCount[26];
    for (int i = 0; i < 26; i++){
        elements[i] = nullptr;
        elementCount[i] = 0;
    }

    Profile aPerson("Maximus");
    Profile secondPerson("Nora");
    string name = aPerson.getName();
    int initial = (int)toupper(name[0]); // the first letter of the name capitalized. We are assuming it is valid since a successful profile was created using it.
   
    for (int i = 0; i < 2; i++){
        elements[initial - 65 + i] = new Profile[5]; 
    }
  
    elements[initial - 65][0] = aPerson;
    elements[initial - 64][0] = secondPerson;
    cout << elements[initial - 65][0] << endl;
    cout << elements[initial-64][0] << endl;
    cout << elements[initial-65][3] << endl;


    */

   string first = "aUsername";
   string second = "aaUsername";
   if (first > second){
    cout << "aUsername is bigger than aaUsername";
   } else if(first == second){
        cout << "They're equal";
   } else{
    cout << "aaUsername is bigger than aUsername";
   }



    return 0;

}
/*
 * MyADT.cpp
 * 
 * Class Description: A linear data collection ADT.
 * 
 * Class Invariant: Data collection with the following characteristics:
 *                  - This is a value-oriented data collection and 
 *                    the elements are kept in ascending sort order of search key.
 *                  - Each element is unique (no duplicates). 
 *                  - Its data structure (CDT) is not expandable. This signifies that 
 *                    when this data collection becomes full, you do not have to resize 
 *                    its data structure (not in this Assignment 1). 
 *
 * Author: AL and Puja Shah
 * Last modified on: Jan. 2024
 */


#include <iostream>
#include <cctype>
#include "MyADT.h"     // Header file of MyADT file
#include "Profile.h"   // Header file of Profile class

using std::cout;
using std::endl;

    
// Default constructor.
MyADT::MyADT() {
   //cout << "MyADT::default constructor executed!" << endl;   // For testing purposes ...
   // You can also use the above to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
 
   /* Put your code here */
   for (int i = 0; i < (int)MAX_ALPHA; i++){      
      elements[i] = nullptr;
      elementCount[i] = 0;
   }
   
}  

// Copy constructor - Covered in Lab 3
MyADT::MyADT(const MyADT& rhs) {
   // cout << "MyADT::copy constructor executed!" << endl; // For testing purposes ... 
   // You can also use the above to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.

   /* Put your code here */
      for (int i = 0; i < (int)MAX_ALPHA; i++){
         if (rhs.elements[i] != nullptr){
            elements[i] = new Profile[MAX_ELEMENTS];
            for (int j = 0; j < (int)rhs.elementCount[i]; j++){
               elements[i][j] = rhs.elements[i][j];
            }

         } else{
            elements[i] = nullptr;
         }

         elementCount[i] = rhs.elementCount[i];
   
   }    
}


// MyADT & MyADT::operator=(const MyADT& rhs) {
   // cout << "MyADT::operator= executed!" << endl; // For testing purposes ... 
   // You can also use the above to figure out when this overloaded assignment = operator is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
   
   /* Put your code here */

//}
    
// Destructor
// Description: Destroys this object, releasing heap-allocated memory.
MyADT::~MyADT() {
   // cout << "MyADT::destructor" << endl;  // For testing purposes ...
   // You can also use the above to figure out when this destructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
   /* Put your code h<ere */
   for (int i = 0; i < (int)MAX_ALPHA ; i++){
      if (elements[i] != nullptr){
         delete[] elements[i];
         elements[i] = nullptr;
      }
   }
   
}  


// Description: Returns the total number of elements currently stored in the data collection MyADT.  
unsigned int MyADT::getElementCount() const {

   /* Put your code here */
   unsigned int total_elements = 0;
   for (int i = 0; i < (int)MAX_ALPHA; i++){
      total_elements += elementCount[i];
   } 

   return total_elements;

}


// Description: Inserts an element in the data collection MyADT.
// Precondition: newElement must not already be in the data collection MyADT.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
//                Returns "true" when the insertion is successfull, otherwise "false".
bool MyADT::insert(const Profile& newElement) {
 
   /* Put your code here */
   int target_array = (int)newElement.getSearchKey() - 97;
   if(elementCount[target_array] == MAX_ELEMENTS){
      return false;
      }
      else{

         if(elements[target_array] == nullptr){
            elements[target_array] = new Profile[MAX_ELEMENTS] ;
         }

         for(int i = 0; i < (int)elementCount[target_array]; i++){    // checking for duplicates
            if (elements[target_array][i] == newElement){
               return false;
            }
         }

         int column = 0;
         while (column < (int)elementCount[target_array] && elements[target_array][column] < newElement){
               column++;
            }

         for (int i = elementCount[target_array]; i > column ; i--){
         elements[target_array][i] = elements[target_array][i -1];
         }

         elements[target_array][column] = newElement;
         elementCount[target_array]++;
         return true;
      }
   }

// Description: Removes an element from the data collection MyADT. 
// Postcondition: toBeRemoved (if found) is removed and the appropriate elementCount is decremented.
//                Returns "true" when the removal is successfull, otherwise "false".  
bool MyADT::remove(const Profile& toBeRemoved) {

   /* Put your code here */
   int initial = (int)(toBeRemoved.getSearchKey()) - 97;
   for (int i = 0; i < (int)elementCount[initial]; i++){
      if (elements[initial][i] == toBeRemoved){
         for (int j = i; j < (int)elementCount[initial] - 1; j++){
            elements[initial][j] = elements[initial][j+1];
         }
         elementCount[initial]--;
         return true;
      }
   }
   return false;
}  


// Description: Removes all elements from the data collection MyADT. 
// Postcondition: MyADT reverts back to its initialization state, i.e., 
//                the state it is in once it has been constructed (once
//                the default constructor has executed). 
void MyADT::removeAll() {
    
    /* Put your code here */
    for (int i = 0; i < (int)MAX_ALPHA; i++){
      if (elements[i] != nullptr){
         delete[] elements[i];
         elementCount[i] = 0;
         elements[i] = nullptr;
      }

    }

}   

// Description: Searches for target element in the data collection MyADT. 
//              Returns a pointer to the element if found, otherwise, returns nullptr.
Profile* MyADT::search(const Profile& target) {
    
    /* Put your code here */
   int initial = (int)(target.getSearchKey()) - 97;
   Profile* to_return = nullptr;
   for(int i = 0; i < (int)elementCount[initial]; i++){
      if(elements[initial][i] == target){
         to_return = &elements[initial][i];
      }
   }

   return to_return;
    

}  


// Description: Prints all elements stored in the data collection MyADT in ascending order of search key.
// ***For Testing Purposes - Not part of this class' public interface.***
void MyADT::print() {
  
    
   for (int i = 0; i < (int)MAX_ALPHA; i++){
      for (int j = 0; j < (int)elementCount[i];j++){
         cout << elements[i][j];
      }
   }

} 

//  End of implementation file
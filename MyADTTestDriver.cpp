/*
 * MyADTTestDriver.cpp
 * 
 * Class Description: Tests methods of the class ADT to ensure adherence to client requirements
 *                    This test driver tests the constructors and other methods i.e print(),
 *                    getElementCount(), insert(), remove(), search(), and removeAll().      
 *
 * Author: Puja Shah
 * Last modified: Jan. 2024
 */



#include <iostream>
#include "Profile.h"
#include "MyADT.h"
using namespace std;

int main(void){

    //Test Case 1
    // Testing creating an ADT using the default constructor
    cout << "Creating a new ADT using the defualt constructor -> MyADT()" << endl;
    cout << "Expected result: empty ADT." << endl;
    MyADT* anADT = new MyADT;
    cout << "Actual result: " << anADT << endl;
    cout << "Testing out the successful generation of elementCount and Print" << endl;
    cout << "Expected result: Number of elements = 0; nothing will get printed" << endl;
    cout << "Number of elements = " << anADT->getElementCount() << endl;
    anADT->print();
    cout << endl;


    //Test Case 2:
    //Testing if the insert function can insert a profile object into an empty stack:
    cout << "Testing to see if a profile is successfully inserted into the empty ADT" << endl;
    cout << "Creating a profile" << endl;
    Profile testingProfile("abUsername", "aName", "anEmail", "aBirthday");
    anADT->insert(testingProfile);
    cout << "Expected result: abUsername, aName, anEmail, born on aBirthday" << endl;
    cout << "Actual result: " ;
    anADT->print();
    cout << "Expected Result: Number of profiles = 1 " << endl;
    cout << "Number of profiles = " << anADT->getElementCount() << endl << endl;

    //Test Case 3:
    // Testing so see if the insert function can successfully add a new profile to an array with a preexisting one
    cout << "Testing to see if the insert function can add a new profile to an array with a preexisting one" << endl;
    Profile testingProfile2("aaUsername", "aName","anEmail","aBirthday");
    anADT->insert(testingProfile2);
    cout << "Simultaneously testing to see if the function is sorting" << endl;
    cout << "Expected result: aaUsername, aName,anEmail,born on aBirthday" << endl <<  "abUsername, aName, anEmail, born on aBirthday" << endl;
    cout << "Actual result: ";
    anADT->print();
    cout << "Testing to see if elementCount was modified. Expected result: 2" << endl;
    cout << "Actual result: " << anADT->getElementCount() << endl  << endl;

    //Test Case 4:
    //Testing to see behavior when attempting to add a duplicate
    cout << "Creating a duplicate profile and attempting to add it" << endl;
    Profile testingProfile3("aaUsername", "aName","anEmail","aBirthday");
    if (anADT->insert(testingProfile3)){
        cout << "Unsuccessfully dealt with a duplicate by adding it instead of denying it" << endl << endl;
    } else{
        cout << "Succesfully did not add a duplicate" << endl << endl;
    }

    //Test Case 5:
    //Testing to see the response to trying to add a profile to a full array (at capacity)
    cout << "Testing to see if attempting to add a new profile to a full array results in not adding it" << endl;
    cout << "Creating and adding 3 more profiles to make it reach full capacity = MAX_ELEMENTS (5 in this case)" << endl;
    Profile testingProfile4("acUsername", "aName", "anEmail", "aBirthday");
    anADT->insert(testingProfile4);
    Profile testingProfile5("adUsername", "aName","anEmail","aBirthday");
    anADT->insert(testingProfile5);
    Profile testingProfile6("aeUsername", "aName","anEmail","aBirthday");
    anADT->insert(testingProfile6);
    cout << "Creating a last profile and trying to add it" << endl;
    Profile testingProfile7("afUsername","aName","anEmail","aBirthday");
    if (anADT->insert(testingProfile7)){
        cout << "Unsuccesfully dealt with capacity restrictions by adding more elements than MAX_ELEMENTS" << endl << endl;
    } else{
        cout << "Successfully adhered to the capacity set by MAX_ELEMENTS and did not exceed it" << endl << endl;
    }

    // Test Case 6
    //Testing to see if elements are successfully removed using the remove function
    cout << "Testing to see if removal of elements has been successful"<< endl;
    cout << "Removing an element" << endl;
    anADT->remove(testingProfile5);  //causes seg fault
    cout << "Should not print testingProfile5 anymore" << endl;
    cout << "Expected result: aaUsername, aName,anEmail,born on aBirthday" << endl <<  "abUsername, aName, anEmail, born on aBirthday" << endl;
    cout << "acUsername, aName,anEmail, born on aBirthday" << endl << "aeUsername, aName, anEmail, born on aBirthday" << endl;
    cout << "Actual result: ";
    anADT->print();
    cout << "Now testing if the elementCount reflects the change" << endl;
    cout << "Expected result: Number of profiles = 4" << endl;
    cout << "Actual result: Number of profiles = " << anADT->getElementCount() << endl << endl;

    //est Case 7
    //Testing to see behavior when attempting to remove a non-existing profile
    cout << "Testing to see behavior when attempting to remove a user that does not exist" << endl;
    cout << "Creating a new profile" << endl;
    Profile testingProfile8("agUsername", "aName", "anEmail", "aBirthday");
    cout << "Removing this elemet from ADT without adding it" << endl;
    if (anADT->remove(testingProfile8)){
        cout << "Unsuccessfully deals with the removal of a non-existent profile" << endl << endl;
    } else{
        cout << "Successfully did not attempt to remove a profile that doesn't exist" << endl << endl;
    }

    //Test Case 8
    // Testing the search function
    cout << "Testing the search function to see if it returns a pointer to the correct element" << endl;
    cout << "Searching for a profile and storing the result" << endl;
    Profile* location_of_profile = anADT->search(testingProfile2);
    cout << "Printing the contents of the profile the pointer leads to" << endl;
    cout << "Expected reuslt: aaUsername, aName,anEmail,born on aBirthday " << endl;
    cout << "Actual result: " ;
    if (location_of_profile != nullptr){
        cout << *location_of_profile << endl;
    } else {
        cout << "Could not successfully search for the right value" << endl << endl;
    }


    //Test Case 9
    //Testing behaviour when searching for a non-existen profile
    cout << "If the search object is not a part of the ADT, it should return a nullptr" << endl;
    cout << "Reusing testingProfile8, that hasn't been inserted" << endl;
    Profile* should_be_null = anADT->search(testingProfile8);
    if (should_be_null == nullptr){
        cout << "Succesfully returned a null pointer when searching for a profile that does not exist" << endl << endl;
    } else{
        cout << "Unsuccessfully deals with a searching a non-existent profile by returning a pointer that is not the nullptr" << endl << endl;
    }


    //Test Csee 10
    // Testing the creation of a new ADT using the copy constructor
    cout << "Testing to see the successfull creation of a new MyADT object with the same print values as the original" << endl;
    cout << "Creating a new ADT by copying anADT" << endl;
    MyADT* copyADT = new MyADT(*anADT);
    cout << "Printing out all the values, which should match anADT" << endl;
    cout << "Expected result : ";
    anADT->print();
    cout << "Actual result : ";
    copyADT->print();
    cout << endl;

    //Test Case 11:
    // Testing to see that the copy constructor results in a deep copy
    cout << "Testing to see that the copy is a deep copy and that changes to one ADT will not reflect on the other" << endl;
    cout << "Creating a profile and adding it to anADT" << endl;
    Profile testingProfile9("mUsername", "aName", "anEmail", "aBirthday");
    anADT->insert(testingProfile9);
    cout << "Expected result:" << endl << "For anADT = ";
    anADT->print();
    cout << "For copyADT: aaUsername, aName,anEmail,born on aBirthday" << endl <<  "abUsername, aName, anEmail, born on aBirthday" << endl;
    cout << "acUsername, aName,anEmail, born on aBirthday" << endl << "aeUsername, aName, anEmail, born on aBirthday" << endl;
    cout << "Actual result: For anADT = ";
    anADT->print();
    cout << "For copyADT: ";
    copyADT->print();
    cout << "Also confirming using element Counts" << endl;
    cout << "Expected result: For anADT = 5, For copyADT = 4" << endl;
    cout << "Actual result: For anADT = " << anADT->getElementCount() << ", For copyADT = " << copyADT->getElementCount() << endl << endl;

    //Test Case 12
    // Testing the removeAll function
    cout << "Testing to see if using the removeall function results in a complete reset" << endl;
    cout << "Checking to see if elementCount is 0" << endl;
    anADT->removeAll();
    if(anADT->getElementCount() != 0){
        cout << "Failed to reset element count" << endl;
    } else{
        cout << "Element count is 0" << endl;
        anADT->print();
        cout << "If the latest output before this statement is about element count, it indicates nothing has been printed, and removeAll succeeded." 
        <<"If there is something else, removeAll failed" << endl;
    }

    //Freeing up memory:
    delete anADT;
    delete copyADT;

    return 0;

}




#include <iostream>
#include <string>
#include <cctype>
using namespace std;
// Remove /* */ to test the output of the program
// Global Inputs to Validate Password
const int charLengthMin = 8,
    charLengthMax = 20;
int invalidChars,           
    missCharTypes;           
string newPassword;
// Function to count Invalid Characters and Missing Character Types
void checkInputSyntax(string newStr);
// Function to check Password Length before Setting up a New Password
string addInput(string newInput, int limitMin, int limitMax);
int main() {
    // Introducion
    cout<<"Note - Syntax to Setup Password"<<endl;
    cout<<"1. Character Limits from "<<charLengthMin<<" to "<<charLengthMax<<endl;
    cout<<"2. Characters Include: Uppercase, Lowercase, Digit, Punctuation"<<endl;
    cout<<"3. Example: stID@2023\n"<<endl;
    newPassword = addInput(newPassword, charLengthMin, charLengthMax);
    /*
    // Display newPassword after Setup
    cout<<newPassword; 
    */
    return 0;
}
// Details of Each Function
string addInput(string newInput, int limitMin, int limitMax) {
    int charLength;
    do {
        cout<<"New Password: ";
        getline(cin, newInput);
        checkInputSyntax(newInput);
        if (invalidChars + missCharTypes > 0) // charLength = 0 until invalidChars && missCharTypes = 0
            charLength = 0;
        else {
            charLength = newInput.length();
            if (charLength < limitMin)
                cout<<"Require "<<limitMin - charLength<<" More Characters to Setup Password!\n"<<endl;
            else if (charLength > limitMax)
                cout<<"Out of Character Limits: "<<charLength<<" Characters!\n"<<endl;
            else
                cout<<"Password Setup is Complete!"<<endl;
        }
    }
    while(charLength < limitMin || charLength > limitMax);
    return newInput;
}
void checkInputSyntax(string newStr) {
    invalidChars = 0;       // Default: User Input is No-Error
    missCharTypes = 4;      // Default: User Input misses 4 Character Types
    int includeDigit = 0,
        includeUpper = 0,
        includeLower = 0,
        includePunct = 0;
    /*
    // Display Lines for each New Character
    int lineIndex = 0;
    */
    for (char randomChar : newStr) {
        if (randomChar < '!' || randomChar > '~')
            invalidChars++;
        /* 
        Ex: newStr = "#c4"
        1st Loop:           2nd Loop:           3rd Loop
        includeUpper = 0    includeUpper = 0    includeUpper = 0
        includeLower = 0    includeLower = 1    includeLower = 1
        includeDigit = 0    includeDigit = 0    includeDigit = 1
        includePunct = 1    includePunct = 1    includePunct = 1
        */
        includeUpper = (isupper(randomChar) || includeUpper > 0)? 1:0;
        includeLower = (islower(randomChar) || includeLower > 0)? 1:0;
        includeDigit = (isdigit(randomChar) || includeDigit > 0)? 1:0;
        includePunct = (ispunct(randomChar) || includePunct > 0)? 1:0;
        /*
        // Expected Output at Final Line:
        // 1   1   1   1 => missCharTypes = 4 - (1 + 1 + 1 + 1);
        lineIndex++;
        cout<<"Line "<<lineIndex<<"\t: ";
        cout<<includeDigit<<"\t";
        cout<<includeUpper<<"\t";
        cout<<includeLower<<"\t";
        cout<<includePunct<<endl;
        */
    }
    missCharTypes = missCharTypes - (includeUpper + includeLower + includeDigit + includePunct);
    if (invalidChars > 0) {
        cout<<"WRONG SYNTAX! - Invalid Counts: "<<invalidChars<<"\n"<<endl;
    }
    else if(missCharTypes > 0) {
        cout<<"INCLUDING AT LEAST:"<<endl;
        if(includeUpper < 1) cout<<"1 Uppercase!"<<endl;
        if(includeLower < 1) cout<<"1 Lowercase!"<<endl;
        if(includeDigit < 1) cout<<"1 Digit!"<<endl;
        if(includePunct < 1) cout<<"1 Punctuation!"<<endl;
        cout<<endl;
    }
}

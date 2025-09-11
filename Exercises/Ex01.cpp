#include <iostream>
using namespace std;

int main()
{
    int guess, random = 0;
    bool isFound = false;
    while(!isFound) {
        random = rand()%100;
        cout<<"Guess my favorite number!\nRange from 0 to 100"<<endl;
        cout<<"Number: ";
        cin >> guess;
        if (guess > 0) {
            if (guess != random)
                cout<<"\nOops, It's "<<random<<", Try Again!"<<endl;
            else {
                isFound = true;
                cout<<"\nCongratulations, You're beat my game :D";
            }
        }
        else {
            cout<<"\nUhh, "<<guess<<"?!\nYou ain't funny..."<<endl;
            break;
        }
    }
    return 0;
}

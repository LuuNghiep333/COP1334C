#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int slot = 1;
    double total = 0, avg = 0, grade[2]; // Array of 'grade' must be over than 1 to prevent from *** stack smashing detected ***: terminated 
    cout<<"How many subjects have you studied in this course? \nSubjects: ";
    cin>>slot;
    for (int i = 0; i < slot; i++)
    {
        cout<<"Subject "<<i+1<<": ";
        cin>>grade[i];
        total = total + grade[i];
    }
    avg = total/slot;
    cout<<"Your average score is "<<setprecision(3)<<avg<<endl;
    return 0;
}

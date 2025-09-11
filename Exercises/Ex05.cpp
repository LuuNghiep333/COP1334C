#include <iostream>
using namespace std;
int main()
{
    int membershipType[3] = {99, 175, 225};
    int slots = 3, memberTypes[3], overalPayForEach[3], totalPay;
    cout<<"How many members for each membership?"<<endl;
    cout<<"1. Individual Membership: ";
    cin>>memberTypes[0];
    cout<<"2. Dual Membership: ";
    cin>>memberTypes[1];
    cout<<"3. Family Membership: ";
    cin>>memberTypes[2];
    for(int i = 0; i < slots; i++)
    {
        overalPayForEach[i] = memberTypes[i] * membershipType[i];
        cout<<"Type "<<i+1<<": "<<overalPayForEach[i]<<endl;
        totalPay = totalPay + overalPayForEach[i];
    }
    cout<<"Total Pay: "<<totalPay;
    return 0;
}

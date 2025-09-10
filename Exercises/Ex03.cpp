#include <iostream>
using namespace std;
int checkFertilize(int input);
int checkPlant(int input);
int main()
{
    int area, num, total, priceArea, priceFertilized, pricePlanted = 0;
    cout<<"Welcome to lawn service!"<<endl;
    cout<<"How large is your lawm? \n Area: ";
    cin>>area;
    if (area < 5000)
    {
        cout<<"Lucky for you, You get Free Mowing!"<<endl;
        priceArea = 0;
    }
    else priceArea = 35*( area/5000);
    priceFertilized = checkFertilize(num);
    pricePlanted = checkPlant(num);
    total = priceArea + priceFertilized + pricePlanted;
    cout<<"Your bill is $"<<total;
    return 0;
}
int checkFertilize(int input)
{
    char check;
    input = 0;
    cout<<"Would you like to fertilize your lawn? \n Y or N: ";
    cin>>check;
    if(check == 'Y' || check == 'y') 
    {
        cout<<"Number of Applications: ";
        cin>>input;
        input = 30 * input;
    }
    return input;
}
int checkPlant(int input)
{
    char check;
    input = 0;
    cout<<"Would you like to plant trees in your lawn? \n Y or N: ";
    cin>>check;
    if(check == 'Y' || check == 'y')
    {
        cout<<"Number of Trees: ";
        cin>>input;
        input = 50 * input;
    }
    return input;
}

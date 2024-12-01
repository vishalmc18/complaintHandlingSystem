#include "date.h"
#include <iostream>
using namespace std;

void date:: setdate()
{
    do{
        cout<<"\n enter day :";
        cin>>day;
        cout<<"\n enter month : ";
        cin>>month;
        cout<<"\n enter year :";
        cin>>year;
    }while(isValidDate(day, month, year)==false);
}
void date:: getdate()
{
    cout<<"\n"<<day<<"/"<<month<<"/"<<year<<"\n";
}
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include "complaint.h"



using namespace std;


complaint calllogin;
  



void login();
void registr();
void forgot();
void AdminLogin();


int complaint :: callmain(){
    int choice;

        cout<<"***********************************************************************\n";
        cout<<"               Welcome to Complaint Handling System                   "<<endl;
        cout<<"                      Welcome to login page                               \n";
        cout<<"*******************        MENU        *******************************\n";
        cout<<"1.USER LOGIN"<<endl;
        cout<<"2.ADMIN LOGIN"<<endl;
        cout<<"3.REGISTER"<<endl;
        cout<<"4.Forgot Password"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"\nPlease Enter your choice :  ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                      
                        login();
                        break;
                case 2:
                        AdminLogin();
                        break;
                case 3:
                        registr();
                        break;
                case 4:
                        forgot();
                        break;
                case 5:
                         cout<<"Thank You!!! \n\n";
                         break;
                default:
                
                        cout<<"Please Enter Correct Choice!!!!!\n"<<endl; 
                       break;
        }


    return choice;
}


void login()
{
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<"please enter the following details"<<endl;
        cout<<"USERNAME :";
        cin>>user;
        cout<<"PASSWORD :";
        cin>>pass;
        
        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)
        
                {
                        
                        count=1;
                        
                        
                }
        }
        input.close();
        if(count==1)
        {
            cout<<"\nHello "<<user<<" LOGIN SUCESS!!! Thanks for logging in\n";
            cin.get();
            calllogin.userlogin();
        }
         
        else
        {
                cout<<"\nLOGIN ERROR!!!Please check your username and password\n\n";
                forgot();
             
        }

     

}

void AdminLogin(){
    int count = 0;
    string username, password;
    fflush(stdin);
    cout<<"please enter the following details"<<endl;
    cout<<"USERNAME :";
    getline(cin, username);
    fflush(stdin);
    cout << "PASSWORD :";
    getline(cin,password);
    if(username == "ADMIN" && password == "ADMIN"){
        cout << "Login successfull as an ADMIN:"<<endl;
        calllogin.adminlogin();
        ifstream fin;
        ofstream fout;
        fin.open("data.txt", ios::binary);
        if(fin.is_open()){
            fout.open("temporary.txt", ios::binary | ios::out | ios::app);
            while(fin.read((char*)&calllogin,sizeof(calllogin))){
                fout.write((char*)&calllogin,sizeof(calllogin));
            }
        }
        else{
            cout<<"fail to open!!"<<endl;
        }
        fin.close();
        fout.close();
        std::remove("data.txt"); 
        std::rename("temporary.txt","data.txt");



    }
    else{
        cout << "sorry please enter the correct admin details"<<endl;
        AdminLogin();
    }
}

void registr()
{
        
        string reguser,regpass,ru,rp;
        system("cls");
        cout<<"Enter the username :"<<endl;
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;
        
        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nRegistration Sucessful\n";
        reg.close();
        login();     
}

void forgot()
{
    int ch;
    system("cls");
    cout << "Forgotten ? We're here for help\n";
    cout << "1.Search your id by username." << endl;
    cout << "2.Search your id by password." << endl;
    cout << "3.Again Registration" << endl;
    cout << "Enter your choice :";
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        int count = 0;
        string searchuser, su, sp;
        cout << "\nEnter your remembered username :";
        cin >> searchuser;
        ifstream searchu("database.txt");
        while (searchu >> su >> sp)
        {
            if (su == searchuser)
            {
                count = 1;
            }
        }
        searchu.close();
        if (count == 1)
        {
            cout << "\n\nHurray, account found\n";
            cout << "\nYour password is " << sp;
            cin.get();
            cin.get();
            system("cls");
            login();
        }
        else
        {
            cout << "\nSorry, Your userID is not found in our database\n";
            cout << "\nPlese register again:\n";
            cin.get();
            cin.get();
            registr();
        }
        break;
    }
    case 2:
    {
        int count = 0;
        string searchpass, su2, sp2;
        cout << "\nEnter the remembered password :";
        cin >> searchpass;
        ifstream searchp("database.txt");
        while (searchp >> su2 >> sp2)
        {
            if (sp2 == searchpass)
            {
                count = 1;
            }
        }
        searchp.close();
        if (count == 1)
        {
            cout << "\nYour password is found in the database \n";
            cout << "\nYour Id is : " << su2;
            cin.get();
            cin.get();
            system("cls");
            login();
        }
        else
        {
            cout << "Sorry, We cannot found your password in our database \n";
            cout << "\nplease register again:"<<endl;
            cin.get();
            cin.get();
            registr();
        }
        break;
    }
    case 3:
    {
        cin.get();
        registr();
    }
    }
}



int main()
{    
    
    calllogin.callmain();
    return 0;
}
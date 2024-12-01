#include <iostream>
#include <fstream>
#include <cstdio>
#include<iomanip>
#include<string.h>
#include "complaint.h"


using namespace std;


complaint status1;




void update(){
    string Dsapid;
    cout<<"SAPID for which you want to update complaint status:"<<endl;
    cin>>Dsapid;
    ifstream fin;
    ofstream fout;
    fin.open("data.txt",ios::binary);          
    fout.open("temporary.txt", ios::out  |  ios::binary | ios::app);
    if(fin.is_open() && fout.is_open()){
        while(fin.read((char*)&status1,sizeof(status1))){
            if(Dsapid==status1.getsapid()){  
            status1.getstatuss();
            fout.write((char*)&status1,sizeof(status1));

            }                
            else{
            
            fout.write((char*)&status1,sizeof(status1));

            }
        }
        cout<<"Status updated successfully !!"<<endl;
    }
    else{
        cout<<"fail to open file!!"<<endl;
    }
    fin.close();
    fout.close();
    
    std::remove("data.txt"); 
    std::rename("temporary.txt","data.txt");
}



void deleteco(){
    int isfound=0;
    string Dsapid;
    ifstream fin;
    ofstream fout;
    fin.open("data.txt", ios::binary);
    fout.open("temporary.txt", ios::binary | ios::out |ios::app);
    cout<<"SAPID for which you want to delete complaint:"<<endl;
    cin>>Dsapid;

    while(fin.read((char*)&status1,sizeof(status1))){ 
        if(Dsapid==status1.getsapid()){ 
            cout<<status1.getsapid()<<endl;
            cout<<"\nThe following Employee will be deleted"<<endl; 
            status1.getsorted(); 
            isfound++; 
        }else{ 
            fout.write((char*)&status1,sizeof(status1)); 
        } 
    }
    fin.close(); 
    fout.close(); 
    if(isfound==0){ 
        cout<<"\nRecord of Employee  "<<Dsapid<<" not found for deletion \n"; 
    } 
    std::remove("data.txt"); 
    std::rename("temporary.txt","data.txt");
    

} 





void alluser(){
    ifstream fin;
    fin.open("data.txt",ios::binary);
    if(fin.is_open()){
    while(fin.read((char*)&status1,sizeof(complaint))){;
        status1.getsorted();
    }
    }
    else{      
        cout<<"fail to open file!"<<endl;
    }      
    fin.close();
}  


void showpendingg(){    
    int isfound=0;
    string string1 = "pending";
    
    
    ifstream st1;
    st1.open("data.txt", ios::binary);
    
    if(st1.is_open()){
        while(st1.read((char*)&status1,sizeof(status1))){
            if(status1.getstatus() == string1){
                    
                    status1.getsorted();
                    isfound=1;
                    
            }
        }
    }      
    else{
        cout<<"Fail to open!!"<<endl;
    }  
    if(isfound==0){
        cout<<"Record not found !!"<<endl;
    }
    st1.close();
}




void showsolvedd(){
    int isfound=0;
    string stst="solved";
    
    ifstream st1;
    st1.open("data.txt", ios::binary);
    
    if(st1.is_open()){
        while(st1.read((char*)&status1,sizeof(status1))){
            if(status1.getstatus() == stst){
                    
                    status1.getsorted();
                    isfound=1;  
                    
            }
        }
    } 
    else{
        cout<<"Fail to open file!!"<<endl;
    }       
    if(isfound==0){
        cout<<"Record not found !!"<<endl;
    }
    st1.close();

}

void complaint :: adminlogin(){

    
char c;
    
do
{
    int ch1;
    cout<<"please select any option."<<endl;
    cout<<"1.Update status of complaint"<<endl;
    cout<<"2.Delete a particular complaint"<<endl;

    cout<<"3.All users data"<<endl;
    cout<<"4.View complaint report with pending status"<<endl;
    cout<<"5.View complaint report with solved status"<<endl;
    cout<<"6.Go to main login page (User/Admin)"<<endl;
    cout<<"7.Exit"  <<  endl  << endl;
    cout<<"Please Enter a Choice:"<<endl;
    cin>>ch1;
switch(ch1)
{  
    case 1:
         update();
         break;


    case 2:
            deleteco();
            break;


    case 3:
            alluser();
            break;


    case 4:
            showpendingg();
            break;


    case 5:
            showsolvedd();
         break;

    case 6:
        status1.callmain();
        break;
    case 7:
        cout<<"Thank you!!";
        exit(8);
        exit(9);
        exit(6);
    
    default :
        cout<<"Please Select Correct choice!!!"<<endl;
        break;
}

    cout<<"\nDo You Want To Continue y/n: \n";
    cin>>c;

}while(c=='y'||c=='Y');

  }
#include <iostream>
#include<fstream>
#include<string>
#include <iomanip>
#include "complaint.h"


using namespace std;




complaint reg;




void registerc()
{
    

ofstream st;
st.open("data.txt",ios::out | ios::binary | ios::app);
   
    
    reg.setcomp();
    reg.setstatus();
    st.write((char*)&reg,sizeof(reg));
    st.close();
    cout<<"record added successfully!"<<endl; 
    

}
void view(){
    int isfound=0;
    string complaintID1;
    cout<<"please enter your SAPID"<<endl;
    cin>>complaintID1;
    ifstream st1;
    st1.open("data.txt", ios::binary |ios::in);
    if(!st1){
        cout<<"fail to open "<<endl;
        return;
            }
    while(!st1.eof()){
        if(st1.read((char*)&reg,sizeof(reg))){
            if(reg.getsapid() == complaintID1){
                    cout<<"complaint found : "<<endl;
                    reg.getcomp();
                    isfound=1;
                    break;
            }
        }
    }        
    if(isfound==0){
        cout<<"complaint not found with this SAPID !"<<endl;
    }
    st1.close();

}
 void updateuser()
 {  
    string complaintIDU;
    int isfound=0;
    int position;
    cout<<"enter your SAPID which u want to update :"<<endl;
    cin>>complaintIDU;
    fstream st2;

    st2.open("data.txt",ios::in|ios::out|ios::binary);
    while(st2.read((char*)&reg,sizeof(reg))){
        position=st2.tellg();
        if((complaintIDU==reg.getsapid())){
            cout<<"following user complaint will be modified:"<<endl;
            reg.getcomp();
            isfound++;
            cout<<endl<<"Re-enter your complaint: "<<endl;
            reg.setcomp();
            st2.seekg(position-sizeof(complaint));
            st2.write((char*)&reg,sizeof(reg));
            cout<<endl<<"user complaint updated successfully!"<<endl;
            break;
        }
    }
    if(isfound==0){
                cout<<endl<<"Record of USER "<<complaintIDU<<" not found for updation \n";
            }
    st2.close();
 }
 
 void feedback()
 {
    string feedback;
    cout<<endl<<"Please Enter Your Feedback\n";
    cin.clear();
    cin.sync();
    getline(cin, feedback);

 }
 
void complaint :: userlogin(){

    char c;
do
{
    int ch;
    cout<<"please select any option.\n";
    cout<<"1.Raise new complaint \n";
    cout<<"2.View Your Complaint \n";
    cout<<"3.Update your last complaint \n";
    cout<<"4.Give Feedback\n";
    cout<<"5.Go to main login page (Admin/User)"<<endl;
    cout<<"6.exit"<<endl<<endl;
    cout<<"Please Enter a Choice:"<<endl;
    cin>>ch;
switch(ch)
{
    case 1:
         registerc();
         break;


    case 2:
        view();
        break;


    case 3:
        updateuser();
        break;


    case 4:
         feedback();
         break;
    case 5:
        reg.callmain();
        break;
    case 6:
        cout<<"Thank you!!"<<endl;
        exit(8);
        exit(8);
        exit(9);
        break;

    default :
        cout<<"Please Select Correct choice!!!"<<endl;
        break;
}

    cout<<"\nDo You Want To Continue y/n: \n";
    cin>>c;

}while(c=='y'||c=='Y');

    }
    

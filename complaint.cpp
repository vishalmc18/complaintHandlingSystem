#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include "complaint.h"

using namespace std;


void complaint::setcomp()
{


do{
	cout<<endl<<"Enter your SAPID : ";
	cin>>sapid;
	}while(isValidSapid(sapid)==false);
	


cout <<endl<<"enter name :";
cin.clear();
cin.sync();
getline(cin,name);

do{
	cout<<endl<<"Enter your Email Address : ";
	cin>>EmailId;
	}while(isValidEmail(EmailId)==false);

do{
	cout<<endl<<"Enter Your Phone Number: ";
	cin>>phnNum;
	}while(isValidContact(phnNum)==false);


cout<<"Enter the date:";
DD.setdate();
cin.clear();
cin.sync();


cout<<"enter complaint description : "<<endl;
getline(cin,desc);


}

string complaint :: setstatus(){
	status="pending";
	return status;
}

void complaint::getcomp()
{
cout<<"\n***Complaint Details***";
cout<<  endl   << "SAPID : "<<sapid;
cout<<  endl   << "Employee name : "<<name;
cout<<  endl   << "Email Address : "<<EmailId;
cout<<  endl   << "Phone Number :  "<<phnNum;
cout<<  endl   << "Complaint Registered Date:  ";
DD.getdate();
cout<<"\ncomplaint description :"<<endl<<desc;
cout<<  endl   << "Status:  "<<status;
}

void complaint :: getsorted(){
    cout<<endl<<sapid<<setw(25)<<name<<setw(40)<<EmailId<<setw(20)<<phnNum<<setw(14)<<status;
}

string complaint::getsapid(){
    return sapid;
}


string complaint::getstatuss(){
	status="solved";
    return status;
}
string complaint::getstatus(){
	
    return status;
}




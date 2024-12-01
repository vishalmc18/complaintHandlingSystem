
#include<string.h>
#include<iostream>
#include "date.h"

using namespace std;

bool isValidContact(string phnNum);
bool isValidSapid(string sapid);
bool isValidEmail(string EmailId);




class complaint{

string name;
string status;
string phnNum;
string sapid;
string EmailId;
string desc;

date DD;            //composition/containment


public:

void userlogin();
void adminlogin();
int callmain();


void setcomp();
void getcomp();
void getsorted();


string setstatus();
string getsapid();
string getstatuss();
string getstatus();

    
};


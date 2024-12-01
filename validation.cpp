#include<iostream>
#include<string.h>
#include<fstream>


using namespace std;



bool isValidSapid(string sapid)
{
    int flag=0;
    if (sapid.length()!=8)
    {
        cout<<"Please Enter correct SAPID!!"<<endl;
        return false;
    }
    if(sapid.length() == 8)
    {
        
        for(int i=0;i<sapid.length();i++)
        {
            if(sapid[0]-48>=5 && sapid[0]-48<=6)
            {
                continue;
            }
            else
            {
                cout<<"Please Enter correct SAPID!!"<<endl;
                return false;
            }
            if(sapid[i]-48>=0 && sapid[i]<=9)
            {
                continue;
            }
            else
            {
                cout<<"Please Enter correct SAPID!!"<<endl;
                
                return false;
            }
        }
        return true;
    }
    cout<<"Please Enter correct SAPID!!"<<endl;
    
    return false;
}
  
bool isValidDate(int dd, int mm, int yy)
{
   
    if(yy<1000 || yy>2022)
    {
        cout<<"Please Enter correct Year!!";
        return false;
    }
    if(mm>12 || mm<0)
    {
        cout<<"Please Enter correct Month!!";
        return false;
    }
    if(mm==2)
    {
        if(((yy % 4 == 0) && (yy % 100 != 0)) || (yy%400 == 0))
        {
            if(dd>28 || dd<0)
            {
                cout<<"Please Enter correct Date!!";
                return false;
            }
        }
        else
        {
            if(dd>29 || dd<0)
            {
                cout<<"Please Enter correct Date!!";
                return false;
            }
        }
    }
    else if(mm==1 || mm==3 || mm==5 || mm==7 ||mm ==8 || mm==10 || mm==12)
    {
        if(dd<0 || dd>31)
        {
            cout<<"Please Enter correct Date!!";
            return false;
        }
    }
    else
    {
        if(dd<0 || dd>30)
        {
            cout<<"Please Enter correct Date!!";
            return false;
        }
    }
    return true;
}


bool isChar(char c)
{
	return ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z'));
}
bool isDigit(const char c)
{
	return (c >= '0' && c <= '9');
}

bool isValidEmail(string EmailId)
{
	if (!isChar(EmailId[0])) 
	{
		return 0;
        // cout
	}
	int At = -1, Dot = -1;
	for (int i = 0; i < EmailId.length(); i++) 
	{
		if (EmailId[i] == '@') 
		{
			At = i;
		}
		else if (EmailId[i] == '.')
		{
			Dot = i;
		}
	}
	if (At == -1 || Dot == -1)
		return 0;

	if (At > Dot)
		return 0;
	return !(Dot >= (EmailId.length() - 1));
}



bool isValidContact(string phnNum)
{
    int flag=0;
    if(phnNum.length()!=10)
    {
        cout<<"Please Enter correct Phone-Number!!"<<endl;
        return false;
    }
    if(phnNum.length() == 10)
    {
        
        for(int i=0;i<phnNum.length();i++)
        {
            if(phnNum[0]-48>=6 && phnNum[0]-48<=9)
            {
                continue;
            }
            else
            {
                cout<<"Please Enter correct Phone-Number!!"<<endl;
                return false;
            }
            if(phnNum[i]-48>=0 && phnNum[i]<=9)
            {
                continue;
            }
            else
            {
                cout<<"Please Enter correct Phone-Number!!"<<endl;
                return false;
            }
        }
        return true;
    }
    cout<<"Please Enter correct Phone-Number!!"<<endl;
    return false;
}
   
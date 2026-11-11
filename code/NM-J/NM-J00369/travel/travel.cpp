#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int a1,a2;
    string b1,b2;
    cin>>a1>>b1>>a2>>b2;
    if(a1==a2)
    {
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	int pai1=0;
	char wei1;
	int x=1;
	for(char a:b1)
	{
		if(a >='0' && a <='9')
		{
			if(x==1)
			{
				pai1 += (a-'0')*10;
				x--;
			}else{
				pai1 += a - '0';
			}
			
		}
		if(a >='A' && a <='Z')
		{
			wei1 = a;
		}
		
	}
	
	int pai2=0;
	char wei2;
	x=1;
	for(char a:b2)
	{
		if(a >='0' && a <='9')
		{
			if(x==1)
			{
				pai2 += (a-'0')*10;
				x--;
			}else{
				pai2 += a - '0';
			}
			
		}
		if(a >='A' && a <='Z')
		{
			wei2 = a;
		}
		
	}
	
	if(pai1 == pai2)
	{
		cout<<"1";
	}else
	{
		cout<<"000";
		return 0;
	}
	
	if(wei1 =='A')
	{
		if( wei2 == 'C')
		{
				cout<<"1";
		}else if(wei2 == 'B')
		{
			cout<<"11";
			return 0;
		}else{
			cout<<"0";
			return 0;
			}
	}
	
	if(wei1 =='B')
	{
		if(wei2 == 'A'|| wei2 == 'C')
		{
				cout<<"11";
				return 0;
		}else{
			cout<<"00";
			return 0;
			}
	}
	
	if(wei1 =='C')
	{
		if(wei2 == 'A')
		{
				cout<<"1";
		}else if(wei2 == 'B')
		{
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
			return 0;
			}
	}
	
	if(wei1 =='D')
	{
		if(wei2 == 'E')
		{
				cout<<"11";
				return 0;
		}else{
			cout<<"00";
			return 0;
			}
	}
	
	if(wei1 =='E')
	{
		if(wei2 == 'D')
		{
				cout<<"11";
				return 0;
		}else{
			cout<<"00";
			return 0;
			}
	}
	cout<<"0";
    return 0;
}

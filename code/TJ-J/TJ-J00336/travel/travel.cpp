#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string l="ABC";
	string r="DF";
	if(a==c)
	{
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1])
		{
			cout<<"1";
			if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))
			{
				cout<<"1";
				if(abs(int(b[2])-int(d[2]))==1)
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"0"<<"0";
			}
		}
		else
		{
			cout<<"0"<<"0"<<"0";
		}
	}
	else
	{
		cout<<"0"<<"0"<<"0"<<"0";
	}
	return 0;
}

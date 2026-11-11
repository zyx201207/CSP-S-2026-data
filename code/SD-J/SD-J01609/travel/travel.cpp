#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
string sa,sb,sc,sd;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("trvael.out","w",stdout);
	cin>>sa>>sb>>sc>>sd;
	char q=sb[2];
	char qq=sd[2];
	if(sa==sc)
	{
		if(sb[0]==sd[0]&&sb[1]==sd[1])
		{
			if((q<='C'&&qq<='C')||(q>='D'&&qq>='D'))
			{
				if(abs((int)(q)-(int)(qq))==1)
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
				}
			}
			else
			{
				cout<<"1100";
			}
		}
		else
		{
			cout<<"1000";
		}
	}
	else
	{
		cout<<"0000";
	}
	cout<<endl; 
	return 0; 
}

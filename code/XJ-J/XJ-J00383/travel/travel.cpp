#include<iostream>
#include<cstdio>
using namespace std;
string c1,c2,c3,c4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3)
	{
		cout<<1;
		int c2n=(c2[0]-'0')*10+c2[1]-'0';
		int c4n=(c4[0]-'0')*10+c4[1]-'0';
		if(c2n==c4n)
		{
			cout<<1;
			int cc=c2[2]-'A'+1,co=c4[2]-'A'+1;
			if(cc+co==9)
			{
				cout<<"1";
			}
			else if(cc+co<=5)
			{
				cout<<1;
				if(cc+co==3||cc+co==5)
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
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

string c1;
string s1;
string c2;
string s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<"1";
			int x=s1[2]-'A';
			int y=s2[2]-'A';
			if(x<=2&&y<=2)
			{
				cout<<"1";
				int z=abs(x-y);
				if(z==1)
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
				if(x>=3&&x<=4&&y>=3&&y<=4)
				{
					cout<<"1";
					int z=abs(x-y);
					if(z==1)
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
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0"<<"0"<<"0"<<"0";
	}
	return 0;
	
	
	
 } 

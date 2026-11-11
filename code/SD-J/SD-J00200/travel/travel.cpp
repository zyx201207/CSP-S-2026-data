#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,p1,p2;
char h1,h2;
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2)
	{
		cout<<"1";
		p1=s1.substr(0,2);
		p2=s2.substr(0,2);
		if (p1==p2)
		{
			cout<<"1";
			h1=s1[2];
			h2=s2[2];
			if ((h1+h2<=132&&h1+h2>=131)||(h1+h2==138))
			{
				cout<<"1";
				if (h1+1==h2)
				{
					cout<<"1";
				}
				else
				cout<<"0";
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

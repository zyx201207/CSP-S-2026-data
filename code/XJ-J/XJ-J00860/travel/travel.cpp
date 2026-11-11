#include<bits/stdc++.h>
using namespace std;
long long a1,b1;
string a2,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)
	{
		if(a2[0]==b2[0]&&a2[1]==b2[1])
		{
			if((a2[2]<='C'&&b2[2]<='C'&&a2[2]!=b2[2])||(a2[2]>='D'&&b2[2]>='D'&&a2[2]!=b2[2]))
			{
				if(a2[2]+1==b2[2]||b2[2]+1==a2[2])
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
	return 0;
} 

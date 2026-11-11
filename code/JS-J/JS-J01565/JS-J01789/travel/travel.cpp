#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)
	{
		cout<<1;
		if(a2.substr(0,2)==b2.substr(0,2))
		{
			cout<<1;
			if((a2[2]=='A'||a2[2]=='B'||a2[2]=='C')&&(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'))
			{
				cout<<1;
				if(abs(a2[2]-b2[2])==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else if((a2[2]=='D'||a2[2]=='F')&&(b2[2]=='D'||b2[2]=='F'))
			{
				cout<<1;
				if(abs(a2[2]-b2[2])==2)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else
			{
				cout<<0<<0;
			}
		}
		else
		{
			cout<<0<<0<<0;
		}
	}
	else
	{
		cout<<0<<0<<0<<0;
	}
	return 0;
}

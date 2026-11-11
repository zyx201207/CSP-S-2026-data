#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	char b[4],d[4];
	cin>>a>>b>>c>>d;
	if(a!=c)
	{
		cout<<0<<0<<0<<0;
	}
	else
	{
		char q=b[0];
		char w=d[0];
		char e=b[1];
		char r=d[1];
		if(q==w&&e==r)
		{
			if(b[2]=='C'&&d[2]=='B')
			{
				cout<<1111;
			}
			else if(b[2]=='B'&&d[2]=='C')
			{
				cout<<1111;
			}
			else if(b[2]=='A'&&d[2]=='B')
			{
				cout<<1111;
			}
			else if(b[2]=='B'&&d[2]=='A')
			{
				cout<<1111;
			}
			else if(b[2]=='D'&&d[2]=='F')
			{
				cout<<1111;
			}
			else if(b[2]=='F'&&d[2]=='D')
			{
				cout<<1111;
			}
			else
			{
				cout<<1100;	
			}	
		}
		else
		{
			cout<<1000;
		}
	}
	return 0;
}
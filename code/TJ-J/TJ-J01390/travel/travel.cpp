#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
	int a,c,a1,c1;
	string b,d;
	cin>>a>>b>>c>>d;
	a1=(b[0]-'0')*10+b[1]-'0';
	c1=(d[0]-'0')*10+d[1]-'0';
	if(a==c)
	{
		cout<<1;
		if(a1==c1)
		{
			cout<<1;
			if(b[2]=='A'&&d[2]=='B'||b[2]=='A'&&d[2]=='C'||b[2]=='B'&&d[2]=='C'||b[2]=='D'&&d[2]=='F'||b[2]=='B'&&d[2]=='A'||b[2]=='C'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'||b[2]=='F'&&d[2]=='D')
			{
				cout<<1;
				if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'||b[2]=='D'&&d[2]=='F'||b[2]=='B'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'||b[2]=='F'&&d[2]=='D')
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
				cout<<00;
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

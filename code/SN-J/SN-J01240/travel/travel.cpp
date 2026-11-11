#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ok=0,tongce=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(a==c and b[0]==d[0] and b[1]==d[1])
	{
		cout<<1;
		if((b[2]=='A' or b[2]=='B' or b[2]=='C') and (d[2]=='A' or d[2]=='B' or d[2]=='C'))
		{
			cout<<1;
			if((b[2]=='A' and d[2]=='B') or (b[2]=='B' and d[2]=='C') or (b[2]=='B' and d[2]=='A') or (b[2]=='C' and d[2]=='B'))
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		else if((b[2]=='E' and d[2]=='F') or (b[2]=='F' or d[2]=='E'))
		{
			cout<<1<<1;
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
	return 0;
}

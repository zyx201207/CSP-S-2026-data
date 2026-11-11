#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
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
	char b1[3],d1[3];
	int t=0;
	for(char i:b)
	{
		b1[t]=i;
		t++;
	}
	t=0;
	for(char i:d)
	{
		d1[t]=i;
		t++;
	}
	if(b1[0]==d1[0]&&b1[1]==d1[1])
	{
		cout<<1;
		if((b1[2]=='D'&&d1[2]=='A'||b1[2]=='D'&&d1[2]=='B'||b1[2]=='D'&&d1[2]=='C')||(b1[2]=='F'&&d1[2]=='A'||b1[2]=='F'&&d1[2]=='B'||b1[2]=='F'&&d1[2]=='C')
		||(b1[2]=='A'&&d1[2]=='D'||b1[2]=='B'&&d1[2]=='D'||b1[2]=='C'&&d1[2]=='D')||(b1[2]=='A'&&d1[2]=='F'||b1[2]=='B'&&d1[2]=='F'||b1[2]=='C'&&d1[2]=='F'))
		{
			cout<<0<<0;
			
		}
		else
		{
			cout<<1;
			if(b1[2]-d1[2]==1||d1[2]-b1[2]==1)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
	}
	else
	{
		cout<<0;
	}
	return 0;
 } 

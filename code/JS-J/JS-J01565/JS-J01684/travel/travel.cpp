#include<bits/stdc++.h>
using namespace std;
bool check1(char a,char b)
{
	if(a=='D'||a=='F')
	{
		if(b=='D'||b=='F')
			return 1;
		else
			return 0;
	}
	else
	{
		if(b=='D'||b=='F')
			return 0;
		else
			return 1;
	}
}
bool check2(char a,char b)
{
	return (abs(a-b)==1);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1])
		{
			cout<<1;
			if(check1(b[2],d[2]))
			{
				cout<<1;
				if(check2(b[2],d[2]))
					cout<<1;
				else
					cout<<0;
			}
			else
				cout<<0<<0;
		}
		else
			cout<<0<<0<<0;
	}
	else
		cout<<0<<0<<0<<0;
	return 0;
}

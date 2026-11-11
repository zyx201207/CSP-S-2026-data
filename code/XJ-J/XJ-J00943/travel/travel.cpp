#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travell.out","w",stdout);
	int a,b;
	string s,h;
	cin>>a>>s>>b>>h;
	if(a==b)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s[0]==h[0]&&s[1]==h[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(s[2]=='C'&&h[2]=='A')
	{
		cout<<"1";
	}
	if(s[2]=='A'&&h[2]=='C')
	{
		cout<<"1";
    }
	if(s[2]=='F'&&h[2]=='D')
	{
		cout<<"11";
	}
	if(s[2]=='D'&&h[2]=='F')
	{
		cout<<"11";
	}
	else if(s[2]=='A'&&h[2]=='B')
	{
		cout<<"11";
	}
	else if(s[2]=='C'&&h[2]=='B')
	{
		cout<<"11";
	}
	else if(s[2]=='B'&&h[2]=='A')
	{
		cout<<"11";
	}
	else if(s[2]=='B'&&h[2]=='C')
	{
		cout<<"11";
	}
	else if(s[2]=='C'&&h[2]=='D')
	{
		cout<<"00";
	}
	else if(s[2]=='D'&&h[2]=='C')
	{
		cout<<"00";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
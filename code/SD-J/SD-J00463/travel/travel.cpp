#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	bool c;
	int r,x;
	r=(a1[0]-'0')*10;
	r=r+(a1[1]-'0')*10;
	x=(b1[0]-'0')*10;
	x=x+(b1[1]-'0')*10;
	if(x==r)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	r=(a2[0]-'0')*10;
	r=r+(a2[1]-'0')*10;
	x=(b2[0]-'0')*10;
	x=x+(b2[1]-'0')*10;
	if(r==x)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if((a2[2]=='D')||(a2[2]=='E'))
	{
		r=1;
	}
	else
	{
		r=0;
	}
	if((b2[2]=='D')||(b2[2]=='E'))
	{
		x=1;
	}
	else
	{
		x=0;
	}
	if(r==x)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if((a2[2]=='D')||(a2[2]=='F')||(a2[2]=='B')||(b2[2]=='B'))
	{
		cout<<"1";
		return 0;
	}
	else
	{
		if(((a2[2]=='A')&&(b2[2]=='B'))||((a2[2]=='B')&&(b2[2]=='C')))
		{
			cout<<"1";
			return 0;
		}
	}
	cout<<"0";
	return 0;
}

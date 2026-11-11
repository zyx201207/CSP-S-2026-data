#include<iostream>
#include<cstdio>
using namespace std;
int c1,c2,x1,x2;
string s1,s2;
char a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else 
	{
		cout<<"0000";
		return 0;
	}
	x1=int(s1[0])*10+int(s1[1]);
	x2=int(s2[0])*10+int(s2[1]);
	if(x1==x2)
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	a=s1[2];
	b=s2[2];
	if(a>='A'&&a<='C'&&b>='A'&&b<='C')
	{
		cout<<1;
		if(a=='A'&&b=='B')
		{
			cout<<1;
		}
		else if(a=='B'&&b=='C')
		{
			cout<<1;
		}
		else if(b=='A'&&a=='B')
		{
			cout<<1;
		}
		else if(b=='B'&&a=='C')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else if(a>='D'&&a<='F'&&b>='D'&&b<='F')
	{
		cout<<"11";
		return 0;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	return 0;
 } 

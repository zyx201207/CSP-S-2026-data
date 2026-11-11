#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a(char x,char y)
{
	if(x=='A')
	{
		if(y=='B'||y=='C')return 1;
		else return 0;
	}
	if(x=='B')
	{
		if(y=='A'||y=='C')return 1;
		else return 0;
	}
	if(x=='C')
	{
		if(y=='A'||y=='B')return 1;
		else return 0;
	}
	if(x=='D')
	{
		if(y=='F')return 1;
		else return 0;
	}
	if(x=='F')
	{
		if(y=='D')return 1;
		else return 0;
	}
}
bool b(char x,char y)
{
	if(x=='A')
	{
		if(y=='B')return 1;
		else return 0;
	}
	if(x=='B')
	{
		if(y=='A'||y=='C')return 1;
		else return 0;
	}
	if(x=='C')
	{
		if(y=='B')return 1;
		else return 0;
	}
	if(x=='D')
	{
		if(y=='F')return 1;
		else return 0;
	}
	if(x=='F')
	{
		if(y=='D')return 1;
		else return 0;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else
	{
		cout<<"1";
		if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<"000";
		else
		{
			cout<<"1";
			if(!a(s1[2],s2[2]))cout<<"00";
			else
			{
				cout<<"1";
				if(!b(s1[2],s2[2]))cout<<"0";
				else cout<<"1";
			}
		}
	}
	return 0;
}

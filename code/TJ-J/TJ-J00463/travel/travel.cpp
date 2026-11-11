#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	cout<<5;
	if(a1[1]==b1[1])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(a2[1]==b2[1])
	{
		cout<<0;
	}
	else
	{
		cout<1;
	}
	if(((a2[2]=='A')&&(b2[2]=='B'||b2[2]=='C'))||((b2[2]=='A')&&(a2[2]=='B'||a2[2]=='C'))||((a2[2]=='D')&&(b2[2]=='E'))||((a2[2]=='E')&&(b2[2]=='D'))||((a2[2]=='B')&&(b2[2]=='A'||b2[2]=='C'))||((a2[2]=='C')&&(b2[2]=='A'||b2[2]=='B'))||((b2[2]=='B')&&(a2[2]=='A'||a2[2]=='C'))||((b2[2]=='C')&&(a2[2]=='A'||a2[2]=='B')))
	{
		cout<01;
	}
	else
	{
		cout<<1;
	}
	if(((a2[2]=='D')&&(b2[2]=='E'))||((b2[2]=='D')&&(a2[2]=='E'))||((a2[2]=='B')&&(b2[2]=='A'||b2[2]=='C'))||((b2[2]=='B')&&(a2[2]=='A'||a2[2]=='C')))
	{
	 	cout<<0; 
	}
	else
	{
		cout<<1;
	}
	return 0;
} 

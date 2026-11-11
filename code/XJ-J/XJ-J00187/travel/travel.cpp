#include <bits/stdc++.h>
using namespace std;
char a[1001];
char a1[1001];
char c[1001];
char c1[1001];
int main()
{
	for(int i=0;i<2;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<3;i++)
	{
		cin>>a1[i];
	}
	for(int i=0;i<2;i++)
	{
		cin>>c[i];
	}
	for(int i=0;i<3;i++)
	{
		cin>>c1[i];
	}
	if(a[0]==c[0])
	{
		if(a[1]==c[1])
		{
			cout<<1;
		}
		else
		{
			cout<<0000;
			return 0;
		}
	}
	else
	{
		cout<<0000;
		return 0;
	}
	if(a1[0]==c1[0])
	{
		if(a1[1]==c1[1])
		{
			cout<<1;
		}
		else
		{
			cout<<000;
			return 0;
		}
	}
	else
	{
		cout<<000;
		return 0;
	}
	if(((a1[2]=='A'||a1[2]=='B'||a1[2]=='C')&&(c1[2]=='A'||c1[2]=='B'||c1[2]=='C'))||((a1[2]=='D'||a1[2]=='F')&&(c1[2]=='D'||c1[2]=='F')))
	{
		cout<<1;
	}
	else
	{
		cout<<00;
		return 0;
	}
	if((a1[2]=='A'&&c1[2]=='B')||(c1[2]=='A'&&a1[2]=='B')||(a1[2]=='B'&&c1[2]=='C')||(c1[2]=='B'&&a1[2]=='C')||(a1[2]=='D'&&c1[2]=='F')||(c1[2]=='D'&&a1[2]=='F'))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}

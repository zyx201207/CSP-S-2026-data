#include <bits/stdc++.h>
using namespace std;
char c1[5],s1[5],c2[5],s2[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=5;i++)
	{
		cin>>c1[i];
	}
	for(int i=1;i<=5;i++)
	{
		cin>>s1[i];
	}
	if(c1[0],c1[1]==s1[0],s1[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	for(int i=1;i<=5;i++)
	{
		cin>>c2[i];
	}
	for(int i=1;i<=5;i++)
	{
		cin>>s2[i];
	}
	if(c2[0],c2[1]==s2[0],s2[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if((c2[2]=='A'||'B'||'C')&&(s2[2]=='A'||'B'||'C'))
	{
		cout<<"1";
	}
	else if((c2[2]=='D'||'F')&&(c2[2]=='D'||'F'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(c2[2]=='A'&&s2[2]=='B')
	{
		cout<<"1";
	}
	else if(c2[2]=='B'||s2[2]=='C')
	{
		cout<<"1";
	}
	else if(c2[2]=='D'||s2[2]=='F')
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
}

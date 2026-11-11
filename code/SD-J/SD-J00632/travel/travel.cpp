#include<bits/stdc++.h>
using namespace std;
int m[6][18];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string c1,s1,c2,s2;
	int a=0,b=0,c=0,d=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a=1;
	}
	else
	{
		a=0;
		b=0;
		c=0;
		d=0;
		cout<<a<<b<<c<<d;
		return 0;
	}
	
	
	if(s1[0]==s2[0])
	{
		b=1;
	}
	else
	{
		b=0;
		cout<<a<<b<<c<<d;
		return 0;
	}
	
	
	
	if((s1[1]=='D')&&(s2[1]=='F'))
	{
       c=1;
	}
	else if((s1[1]=='F')&&(s2[1]=='D'))
	{
		c=1;
	}
	else if (((s1[1]=='A')||(s1[1]=='B')||(s1[1]=='C'))&&((s2[1]!='D')||(s2[1]!='F')))
	{
		c=1;
	}
	else
	{
		
		c=0;
		cout<<a<<b<<c<<d;
		return 0;
	}
	
	
	
	if((s1[1]=='A')&&(s2[1]=='B'))
	{
		d=1;
	}
	else if((s1[1]=='B')&&((s2[1]=='C')||(s2[1]=='A')))
	{
		d=1;
	}
	else if((s1[1]=='C')&&(s2[1]=='B'))
	{
		d=1;
	}
	else if((s1[1]=='D')&&(s2[1]=='F'))
	{
		d=1;
	}
	else if((s1[1]=='F')&&(s2[1]=='D'))
	{
		d=1;
	}
	else
	{
		d=0;
		cout<<a<<b<<c<<d;
		return 0;
	}
	cout<<a<<b<<c<<d;
	return 0;
}

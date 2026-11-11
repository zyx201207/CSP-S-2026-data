#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a=false,b=false,c=false,d=false;
	//a
	if(c1==c2)
	{
		a=true;
	}
	else
	{
		a=false,b=false,c=false,d=false;
	}
	
	//b
	if(a)
	{
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			b=true;
		}
		if(s1[0]==s2[0]&&s1[1]!=s2[1])
		{
			b=false;
		}
		if(s1[0]!=s2[0]&&s1[1]==s2[1])
		{
			b=false;
		}
	}
	//c
	if(b)
	{
		if(s1[2]=='A'&&(s2[2]!='F'&&s2[2]!='D'))
		{
			c=true;
		}
		if(s1[2]=='B'&&(s2[2]!='C'&&s2[2]!='D'))
		{
			c=true;
		}
		if(s1[2]=='C'&&(s2[2]!='C'&&s2[2]!='D'))
		{
			c=true;
		}
		if(s1[2]=='D'&&(s2[2]!='A'&&s2[2]!='B'&&s2[2]!='C'))
		{
			c=true;
		}
		if(s1[2]=='F'&&(s2[2]!='A'&&s2[2]!='B'&&s2[2]!='C'))
		{
			c=true;
		}

	}
	//d
	if(c)
	{
		if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A'))
		{
			d=true;
		}
		if((s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B'))
		{
			d=true;
		}
		if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
		{
			d=true;
		}
		
	}
	
	cout<<a<<b<<c<<d;
	return 0;
}

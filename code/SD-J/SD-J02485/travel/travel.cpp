#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
int man(string s)
{
	int a=0;
	if(s[0]=='1')
	a+=10;
	a+=(s[1]-'0');
	return a;
}
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	bool a=0,b=0,c=0,d=0;
	if(s1!=s3)
	{
		cout<<"0000";return 0;
	}
	a=1;
	if(s2[0]==s4[0]&&s2[1]==s4[1])
	b=1;
	if(b==1)
	{
		if((s2[2]>='D'&&s4[2]>='D')||(s2[2]<='C'&&s4[2]<='C'))
		c=1;
	}
	if(abs(s2[2]-s4[2])==1&&b==1)
	{
		d=1;
		if((s2[2]=='C'&&s4[2]=='D')||(s2[2]=='D'&&s4[2]=='C'))
		d=0;
	}
	
	if(b!=1&&s2[2]==s4[2])
	{
		int c1=man(s2),c2=man(s4);
		if(abs(c1-c2)==1)
		d=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
}

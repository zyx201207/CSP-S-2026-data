#include<bits/stdc++.h>
using namespace std;
int a1,a2,a3,a4;
int main()
{
	string s1,c1,s2,c2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a1=1;
	}
	if(c1!=c2)
	{
		a1=0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&a1==1)
	{
		a2=1;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]||a1==0)
	{
		a2=0;
	}
	if(s1[2]>'C'&&s2[2]>'C'&&a2==1)
	{
		a3=1;
	}
	if(s1[2]<='C'&&s2[2]<='C'&&a2==1)
	{
		a3=1;
	}
	if((s1[2]>'C'&&s2[2]<='C')||(s1[2]<='C'&&s2[2]>'C')||a2==0)
	{
		a3=0;
	}
	if((s1[2]-1==s2[2]||s2[2]-1==s1[2])&&a3==1)
	{
		a4=1;
	}
	else
	{
		a4=0;
	}
	cout<<a1<<a2<<a3<<a4;
	return 0;
 } 

#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool f=1;
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		f=0;
	}
	if(f&&s2[0]==s4[0]&&s2[1]==s4[1])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		f=0;
	}
	if(f&&((s2[2]<='C'&&s4[2]<='C')||(s2[2]>'C'&&s4[2]>'C')))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		f=0;
	}
	if(f&&((abs(s2[2]-s4[2])==1&&s2[2]!='D'&&s4[2]!='D')||(s2[2]=='D'&&s4[2]=='F')||(s2[2]=='F'&&s4[2]=='D')))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}

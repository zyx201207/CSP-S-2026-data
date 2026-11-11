#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2,sp1,sp2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	sp1+=s1[0];
	sp1+=s1[1];
	sp2+=s2[0];
	sp2+=s2[1];
	if(c1==c2)
	{
		cout<<'1';
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(sp1==sp2)
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(s1[2]>='E'&&s1[2]<='F'&&s2[2]>='E'&&s2[2]<='F')
	{
		cout<<"11";
	}
	else if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
	{
		cout<<1;
		if(abs(s1[2]-s2[2])<=1)
		{
			cout<<'1';
		}
		else
		{
			cout<<'0';
		}
	}
	else
	{
		cout<<"00";
		return 0;
	}
	return 0;
}
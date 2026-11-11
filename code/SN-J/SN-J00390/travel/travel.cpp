#include <bits/stdc++.h>
using namespace std;
char a[100];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int ans,sum;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if((s1[0]+s1[1]==s2[0]+s2[1] && c1 !=c2)|| (s1[0]+s1[1]!=s2[0]+s2[1]))
	{
		cout<<0;
	}
	else if(s1[0]+s1[1]==s2[0]+s2[1] && c1==c2)
	{
		cout<<1;
	}
	if((s1[2]>='A' && s1[2]<='C'&& s2[2]>='A'&& s2[2]<='C') && c1!=c2)
	{
		cout<<0;
	}
	else if(s1[2]>='A' && s1[2]<='C'&& s2[2]>='A'&& s2[2]<='C' && (c1==c2)&& (s1[0]+s1[1]==s2[0]+s2[1]))
	{
		cout<<1;
	}
	
	if(s1[2]>='D' && s1[2]<='F' && s2[2]>='D'&& s2[2]<='F' && c1!=c2)
	{
		cout<<0;
	}
	else if(s1[2]>='D' && s1[2]<='F' && s2[2]>='D'&& s2[2]<='F' && (c1==c2)&& (s1[0]+s1[1]==s2[0]+s2[1]))
	{
		cout<<1;
	}
	ans=s1[2]-'0';
	sum=s2[2]-'0';
	if(ans-1==sum || ans+1==sum)
	{
		if(c1==c2)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else if(ans-1 !=sum ||ans+1 !=sum)
	{
		cout<<0;
	}
	return 0;
}
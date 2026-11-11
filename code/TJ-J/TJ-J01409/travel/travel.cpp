#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	string a1="";
	for(int i=0;i<s1.size()-1;i++)
	{
		a1+=s1[i];
	 } 
	 string a2="";
	for(int i=0;i<s2.size()-1;i++)
	{
		a2+=s2[i];
	 } 
	if(a1==a2&&c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C')||s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')||s1[2]=='C'&&(s2[2]=='B'||s2[2]=='A')||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'&&a1==a2&&c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(a1==a2&&c1==c2&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F'))||((s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s2[2]=='D')))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
char s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>s1>>m>>b>>s2;	
	if(n==m)
	{
		cout<<1;
	 } 
	else
	{
		cout<<"0000";
		return 0;
	 } 
	if(a==b)
	{
		cout<<1;
	 } 
	else 
	{
		cout<<"000";
		return 0;
	}
	if(s1>='D'&&s2>='D') 
	{
		cout<<"11";
		return 0;
	}
	if(s1<='C'&&s2<='C')
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(s1-s2)==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200010];
char c[200010];
string s,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,ct=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i],&c[i]);
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
	for(int i=n;i>=1;i--)
		for(int j=1;j<=a[i];j++) r+=c[i];
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=r[i]) ct++;	
	}	
	cout<<ct/2;
	return 0;
}

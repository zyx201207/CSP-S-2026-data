#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string l="";
char z;
int n,t,r,g,zg=0,c=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>g>>z;
		zg+=g;
		for(int j=1;j<=g;j++) l+=z;
	}
	n=zg;
	t=(zg-(zg%2))/2;
	for(int i=0;i<n;i++)
	{
		r=n-i-1;
		if(l[i]!=l[r]) c++;
		if(i>=t) break;
	}
	cout<<c;
	return 0;
}

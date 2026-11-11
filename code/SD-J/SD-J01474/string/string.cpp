#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int zong=0;
	string ac;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		zong+=a;
		for(int j=1;j<=a;j++)
		{
			ac+=c;
		}
	}
	bool huiwen=true;
	for(int i=1;i<=n/2;i++)
	{
		if(ac[i]!=ac[zong-i])
		{
			huiwen=false;
		}
	}
	if(huiwen==true)
	{
		cout<<0;
	}
	else
	{
		cout<<zong/2;
	}
	return 0;
}

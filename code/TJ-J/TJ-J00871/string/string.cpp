#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
long long n,a,cnt;string s,ss;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=0;i<n;i++)
	{ 
		cin>>a>>s;
		for(int j=0;j<a;j++)
			ss+=s;
	}
	int l=0,r=ss.length()-1;
	while(l<r)
	{
		if(ss[l]!=ss[r])
		{
			cnt++;
			ss[r]=ss[l];
		}
		l++;r--;
	}
	cout<<cnt;
	return 0;
 } 

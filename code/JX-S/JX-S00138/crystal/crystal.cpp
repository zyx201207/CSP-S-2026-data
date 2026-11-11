#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>

using namespace std;
int main()
{
	int n=0;
	long long m=0;
	int a[50001];
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d",&n);
	cin>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	long long c=0;
	long long v=0;
	while(c<=m)
	{

		c+=(v+1)*(a[v+1]-a[v]);
		v++;
	}
	cout<<v;
	return 0;
}

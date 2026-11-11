#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int n,m,num,y[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>y[i];
	}
	sort(y,y+n);
	cout<<y[n-m];
	return 0;
}

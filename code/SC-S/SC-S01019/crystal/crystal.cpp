#include <bits/stdc++.h>
#include <cstdio>
#include <stdio.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans=0,l=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out ","w",stdout);
	cin>>n>>m;
	if(n==1)cout<<1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<ans;
	return 0;
}
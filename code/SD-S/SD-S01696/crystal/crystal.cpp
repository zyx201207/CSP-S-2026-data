#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m,s=0,sum=0,ans=0;
bool flag=0,a=1;
ll rp[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> rp[i];
	sort(rp+1,rp+n+1);
	for(int i=1;i<=n;i++)
	{
		sum+=rp[i];
		s+=rp[n]-rp[i];
		if(s<=m)
			flag=1;
		if(sum/n==rp[i])
		{
			flag=1;
		}
		else
		{
			flag=0;
		}	
		if(sum==(rp[1]+rp[n])*n/2)
		{
			if(m>=sum-rp[n])
				flag=1;
		}
	}
	if(flag==1)
		cout << n;
	return 0;
}

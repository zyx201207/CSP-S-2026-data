#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
#define int long long
#define fir first
#define sec second
#define lc u<<1
#define rc u<<1|1
#define ull unsigned long long
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int INF=-1e18;
const int N=5e5+10;
int a[N],b[N],dp[N];
signed main()
{
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout); 
	ios;
	int n,m;
	cin>>n>>m;
	bool A=1;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]!=i) A=0;
	}
	sort(a+1,a+n+1);
	if(A)	
	{
		int ans;
		for(int i=1;i<=n;i++)
		{
			if(((i-1)*(i)>>1)<=m) ans=i;
		}
		cout<<ans;
    }
	else if(n<=5000)
	{
		b[1]=1;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<i;j++) b[i]+=abs(a[i]-a[j]);
		}
		cout<<upper_bound(b+1,b+n+1,m)-b-1;
	}
	else 
	{
		for(int i=1;i<=n;i++) dp[i]=dp[i-1]+(i-1)*(a[i]-a[i-1]);
		int ans=0;
		cout<<upper_bound(dp+1,dp+n+1,m)-dp-1;
	}
	return 0;
} 
/*
5 8
-3 -1 2 2 7
 */

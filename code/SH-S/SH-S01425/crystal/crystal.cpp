#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[500005];
int solve(int n,int m)
{
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(a[n]*(n-mid)-sum[n-1]+sum[mid-1]<=m)
		{
			r=mid;
		}else{
			l=mid+1;
		}
	}
	return n-l+1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	unsigned long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int maxn=1;
	for(int i=2;i<=n;i++)
	{
		int ans=solve(i,m);
		int j=i+1;
		while(a[j]==a[i])
		{
			ans++;
			j++;
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}

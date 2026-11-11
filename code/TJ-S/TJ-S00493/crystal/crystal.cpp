#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],maxn;
map<long long,long long> mp; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		long long maxv=a[i];
		mp[a[i]]++;
		for(int j=1;j<=i;j++) 
		{
			sum[i]+=abs(a[i]-a[j]);
			maxv=max(maxv,a[j]);
		}
		if(sum[i]==m) 
		{
			mp[maxv]=i;
		}
		else if(sum[i]>m&&sum[i-1]<m)
		{
			mp[maxv-1]=i-1;
		} 
	}
	for(int i=1;i<=n;i++)
	{
		maxn=max(mp[a[i]],maxn);
	}
	cout<<maxn;
	return 0;
} 

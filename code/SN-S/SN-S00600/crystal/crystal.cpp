#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005];
int n,m;
int f(int l,int x)
{
	int ans=0;
	int r=x;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[x]*(x-mid+1)-(sum[x]-sum[mid-1])<=m)
		{
			r=mid-1;
			ans=x-mid+1;
		}
		else
		{
			l=mid+1;
		}
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
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
	int r=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,f(1,i));
	}
	cout<<ans;
	return 0;
}

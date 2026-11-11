#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long check(long long mid)
{
	long long sum=0;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		//sum+=max(0,a[i]-mid);
		if(a[i]<=mid)
		{
			sum+=mid-a[i];
			ans+=1;
		}
		if(sum>m)return 0;
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long l=1e12,r=-1e12;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	long long ans=0;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(check(mid)!=0)
		{
			l=mid+1;
			ans=max(check(mid),ans);
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}


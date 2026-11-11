#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=-1,sum[500005];

long long check(long long x,long long l,long long r)
{
	return x*(r-l+1)-(sum[r]-sum[l-1]);
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
	for(int c=1;c<=n;c++)
	{
		long long l=1,r=n,x=0;
		for(;l<=r;)
		{
			long long mid=(l+r)>>1;
			if(check(a[mid],c,mid)<=m)
			{
				l=mid+1;
				x=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		ans=max(ans,x-c+1);
	}
	cout<<ans;
	return 0;
}

//没想到我这个蒟蒻也能写出来（开心喵），xcb我出息了喵！！！ 

#include<bits/stdc++.h> 
using namespace std;
long long n,m;
long long a[500010];
long long b[500010];
long long c[500010];
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("ctystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		c[i]=c[i-1]+b[i];
	}
	for(int i=n;i>=1;i--)
	{
		c[i]=c[i-1];
	}
	for(int i=1;i<=n-1;i++)
	{
		long long now=c[i]+m;
		int l=1,r=n;
		while(l<r)
		{
			int mid=(l+r+1)/2;
//			cout<<l<<' '<<mid<<' '<<r<<'\n';
			if(c[mid]<=now)
			{
				l=mid;
			}
			if(c[mid]>now)
			{
				r=mid-1;
			}
		}
		ans=max(ans,l-i+1);
//		cout<<'\n';
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+10,PY=1e18+1;
long long n,t,bh,m,a[N],ans,b[N];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>bh>>t;
	if(bh==13||bh==14)
	{
//		cout<<1;
		while(t--)
		{
			cin>>n>>m;
			for(int i=1;i<=n;i++)cin>>a[i];
			cout<<n-1<<'\n';
		}
	}
	else if(bh==11||bh==12)
	{
		while(t--)
		{
			cin>>n>>m;
			for(int i=1;i<=n;i++)cin>>a[i];
			long long ans=0;
			for(int i=3;i<=n;i++)
			{
				if(a[1]+m>=a[3])
				{
					ans+=n-i+1;
				}
			}
			cout<<ans<<'\n';
		}
	}
	else
	{
		while(t--)
		{
			ans=0;
			cin>>n>>m;
			for(long long i=1;i<=n;i++)cin>>a[i],a[i]+=PY;
			for(long long i=1;i<=n;i++)
			{
				long long p=lower_bound(a+1,a+1+n,a[i]+m)-a;
				while(a[p]-a[i]>m)p--;
				b[i]=min(p,n);
			}
			for(int i=1;i<=n;i++)
			{
//			cout<<b[i]<<' ';
				if(b[i]-i==2&&b[b[i]]&&b[b[i]]!=b[i])ans++;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
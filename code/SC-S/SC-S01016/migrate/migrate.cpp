/*
抠出来 48 pts
n^2 40
特殊性质 A 8
exp:48pts
fin:17:21
*/
#include<bits/stdc++.h>
using namespace std;
const int N=2000020;
int n;
long long d;
long long a[N];
long long dis[N];
namespace subtask1
{
	long long dp[N],sum[N];
	int nw[N];
	void solve()
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			int l=i;
			dp[i]=1;dp[i-1]=0;
			sum[i]=1;sum[i-1]=0;
			nw[i]=0;
			int r=i;
			for(int j=i+1;j<=n;j++)
			{
				dp[j]=0;
				while(dis[j]-dis[l]>d) l++;
				r=max(r,l);
				nw[j]=nw[l]+1;
				while(r<j&&nw[r+1]<nw[j]) r++;
				dp[j]=sum[r]-sum[l-1];
				if(dp[j]==0) break;
				sum[j]=dp[j]+sum[j-1];
//				cerr<<i<<':'<<l<<' '<<r<<'\n';
				if(dp[j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
};
long long flagA;
namespace A
{
	void solve()
	{
		long long D=a[2]-a[1];
		if(d<D*2)
		{
			cout<<0<<'\n';
			return;
		}
		long long len=d/D+d/D;
		cout<<max((long long)n-len+1,0ll)<<'\n';
	}
};
void solve()
{
	cin>>n>>d;
	flagA=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1)
		{
			dis[i]=dis[i-1]+a[i]-a[i-1];
			if(!flagA) continue;
			if(flagA==-1) flagA=a[i]-a[i-1];
			if(flagA!=a[i]-a[i-1])
			{
				flagA=0;
			}
		}
	}
	if(flagA)
	{
		A::solve();
		return;
	}
//	if(n<=5000)
//	{
		subtask1::solve();
		return;
//	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int sid,T;
	cin>>sid>>T;
	while(T--) solve();
	return 0;
}

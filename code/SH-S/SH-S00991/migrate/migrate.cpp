#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,T,n;
namespace subS
{
	const int N=505;
	int dis[N][N],cnt[N][N];
	ll d,ans,x[N];
	void solve()
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=N;
				cnt[i][j]=0;
			}
		ans=0;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			dis[i][i]=0;
			cnt[i][i]=0;
			for(int j=i+1;j<=n;j++)
				if(x[j]-x[i]<=d)
				{
					dis[i][j]=1;
					cnt[i][j]=1;
				}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
				{
					if(dis[j][i]+dis[i][k]<dis[j][k])
					{
						dis[j][k]=dis[j][i]+dis[i][k];
						cnt[j][k]=cnt[j][i]*cnt[i][k];
					}
					else if(dis[j][i]+dis[i][k]==dis[j][k])
						cnt[j][k]+=cnt[j][i]*cnt[i][k];
					if(cnt[j][k]>2)cnt[j][k]=3;
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(cnt[i][j]==2)ans++;
		cout<<ans<<'\n';
	}
}
namespace subC
{
	const int N=2e6+5;
	int cnt[N];
	ll d,ans,x[N];
	void solve()
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			cnt[i]=0;
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			int lp=lower_bound(x+1,x+i+1,x[i]-d)-x;
			if(lp<i-1)cnt[lp]++;
		}
		for(int i=1;i<=n;i++)
		{
			int rp=upper_bound(x+i,x+n+1,x[i]+d)-x-1;
			if(rp>i+1)ans+=cnt[rp-1];
		}
		cout<<ans<<'\n';
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c>=11)
	{
		while(T--)subC::solve();
	}
	else
	{
		while(T--)subS::solve();
	}
	return 0;
}

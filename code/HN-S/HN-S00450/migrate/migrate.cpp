#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5; 
int c,t,n,d,x[N],nxt[N],dp[N],ans,cnt[N],pa[N][25],sum[N][25];
int lca(int a,int b)
{
	for(int i=20;i>=0;i--)if(pa[a][i]!=pa[b][i])a=pa[a][i],b=pa[b][i];
	return pa[a][0];
}
int s(int a,int b)
{
	int ans=0;
	for(int i=20;i>=0;i--)if(pa[a][i]!=pa[b][i])ans+=sum[b][i]-sum[a][i],a=pa[a][i],b=pa[b][i];
	return ans;
}
void solve()
{
	cin>>n>>d;
	dp[n+1]=0;
	ans=0;
	for(int i=1;i<=n;i++)cin>>x[i],dp[i]=0,cnt[i]=1;
	for(int i=n;i>=1;i--)nxt[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1,pa[i][0]=nxt[i],sum[i][0]=nxt[i];
	for(int i=1;i<=20;i++)for(int j=1;j<=n;j++)pa[j][i]=pa[pa[j][i-1]][i-1],sum[j][i]=sum[j][i-1]+sum[pa[j][i-1]][i-1];
	for(int i=n;i>=1;i--)
	{
		if(nxt[i]==i)continue;
		if(nxt[i]==i+1)
		{
			dp[i]=dp[nxt[i]];
			if(nxt[i-1]!=nxt[i])cnt[i]+=cnt[nxt[i]]+nxt[i]-nxt[i-1]-1;
			continue;
		}
		int c=lca(nxt[i]-1,nxt[i]);
		if(nxt[c]==c)
		{
			cnt[i]=s(nxt[i-1],nxt[i])+1;
			dp[i]=nxt[nxt[i]-1]-max(nxt[i],nxt[nxt[i]-2])+dp[c];
			continue;
		}
		cnt[i]=s(nxt[i-1],nxt[i])+1;
		dp[i]=nxt[nxt[i]-1]-max(nxt[i],nxt[nxt[i]-2])+cnt[lca(nxt[i]-1,nxt[i])];
	}
	for(int i=1;i<=n;i++)ans+=dp[i];
	cout<<ans<<'\n'; 
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}


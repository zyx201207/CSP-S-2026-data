#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2,maxm=1e4;
int c,n,m,d,q;
long long w[maxm+5],t[maxn+5][maxm+5];
long long f[maxm+5][maxm+5];
bool vis[maxm+5];
int cnt[maxm+5],cntc=0,change[maxm+5];
void solve(int u,int v)
{
	if(f[u][v]!=-1) return;
	bool flag=0;
	long long ans=9e18;
	for(int i=1;i<=n;i++)
	{
		if(t[i][u]&&t[i][v])
		{
			flag=1;
			ans=min(ans,t[i][u]+t[i][v]);
		}
	}
	if(flag)
	{
		f[u][v]=f[v][u]=ans;
		return;
	}
	for(int i=1;i<=cntc;i++)
	{
		int p=change[i];
		if(vis[p]) continue;
		vis[p]=1;
		solve(u,p),solve(p,v);
		ans=min(ans,f[u][p]+f[p][v]);
		vis[p]=0;
	}
	f[u][v]=f[v][u]=ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,-1,sizeof(f));
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=m;i++) f[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		int k,st=0;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int a;
			scanf("%d",&a);
			scanf("%lld",&t[i][a]);
			cnt[a]++;
		}
	}
	for(int i=1;i<=m;i++) if(cnt[i]>=2) change[++cntc]=i;
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) solve(i,j);
	while(q--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		long long ans=w[x]+w[y]+f[x][y];
		printf("%lld\n",ans);
	}
	return 0;
}

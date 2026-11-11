#include<bits/stdc++.h>
#define LL long long
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define dow(i,j,k) for(int i=j;i>=k;i++)
using namespace std;
const int N=1e6+5;
int c,T;
int n,k;
vector<int> e[N];
bool vis[N];
int dfs(int u,int fa)
{
	if(vis[u]) return 0;
	int ans=100;
	for(int v:e[u])
	{
		if(v==fa) continue;
		ans=min(ans,dfs(v,u));
	}
	return ans+1;
}
bool col[N];
void dfs2(int u,int fa)
{
	if(!vis[u])
	{
		col[u]=0;
		return;
	}
	col[u]=1;
	for(int v:e[u])
	{
		if(v==fa) continue;
		dfs2(v,u);
	}
}
void solve1()
{
	int W=(1<<n)-1;
	int ans=100;
	rep(bit,0,W)
	{
		int cnt=0;
		rep(i,1,n)
		{
			int op=(bit>>i-1)&1;
			cnt+=op;
			vis[i]=op;
			col[i]=0;
		}
		if(cnt!=k) continue;
		cnt=0;
		rep(i,1,n) if(vis[i]&&!col[i]) dfs2(i,2),cnt++;
		if(cnt>2) continue;
		int now=0;
		rep(i,1,n) now=max(now,dfs(i,0));
		ans=min(ans,now);
	}
	printf("%lld\n",ans);
}
//void solve2()
//{
//	int m=n/2;
//	cout<<m;
//	m-=k;
//	printf("%d\n",m/3);
//}
void solve()
{
	scanf("%d%d",&n,&k);
	rep(i,1,n) e[i].clear();
	rep(i,1,n-1)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(c<=3) solve1();
//	if(c==13||c==14) solve2();
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--) solve();
	return 0;
}
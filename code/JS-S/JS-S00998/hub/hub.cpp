#include <bits/stdc++.h>
#define int long long
using namespace std;
int Subid,T,n,m,U[1000005],V[1000005],dis[15],f[15];
vector<int> g[1000005];
void dfs(int u,int dep)
{
	if(dis[u]>dep) dis[u]=dep;
	else return ;
	for(auto v:g[u]) dfs(v,dep+1);
}
int fi(int x)
{
	if(f[x]==x) return x;
	return f[x]=fi(f[x]);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&Subid,&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);int ans=1e9;
		for(int i=0;i<n;i++) g[i].clear();
		for(int i=1;i<n;i++) scanf("%lld%lld",U+i,V+i),U[i]--,V[i]--,g[U[i]].emplace_back(V[i]),g[V[i]].emplace_back(U[i]);
		for(int i=0;i<(1<<n);i++) if(__builtin_popcount(i)==m)
		{
			memset(dis,0x3f,sizeof(dis));
			int res=0,cnt=0;
			for(int j=0;j<n;j++) if((i>>j)&1) dfs(j,0);
			for(int j=0;j<n;j++) res=max(res,dis[j]);
			for(int j=0;j<n;j++) f[j]=j;
			for(int j=1;j<n;j++) if(((i>>U[j])&1)&&((i>>V[j])&1)) f[fi(U[j])]=fi(V[j]);
			for(int j=0;j<n;j++) if((i>>j)&1) cnt+=(f[j]==j);
			if(cnt<=2) ans=min(ans,res);
		}
		printf("%lld\n",ans);
	}
}
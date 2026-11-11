#include<bits/stdc++.h>
//#define int long long
#define ull unsigned long long
#define double long double
#define endl '\n'
#define pb push_back
#define now_time (1e3*clock()/CLOCKS_PER_SEC)
#define swap(_1_,_2_) _1_^=_2_^=_1_^=_2_
using namespace std;
const int inf=INT_MAX>>1;
int c,T,n,k,d[1000005],up[1000005][20],fa[15],p[15],ans;
struct Edge{int to,ne;}e[2000005];int h[1000005],idx;
bool f[15],ee[5005][5005],ff[15];
inline void add(const int u,const int v){e[++idx]={v,h[u]},h[u]=idx;}
inline void dfs(const int u,const int from)
{
	d[u]=d[up[u][0]=from]+1;
	for(int i=1;i<20;i++)
		up[u][i]=up[up[u][i-1]][i-1];
	for(int i=h[u],v=e[i].to;i;i=e[i].ne,v=e[i].to)
		if(v!=from)dfs(v,u);
}
inline int lca(int u,int v)
{
	if(d[u]<d[v])swap(u,v);
	for(int i=19;~i;i--)
		if(d[up[u][i]]>=d[v])u=up[u][i];
	if(u==v)return u;
	for(int i=19;~i;i--)
		if(up[u][i]!=up[v][i])u=up[u][i],v=up[v][i];
	return up[u][0];
}
inline int find(int x){while(x!=fa[x])x=fa[x]=fa[fa[x]];return x;}
inline bool check()
{
	for(int i=1;i<=k;i++)
		fa[i]=i,ff[i]=0;
	for(int i=1;i<=k;i++)
		for(int j=i+1;j<=k;j++)
			if(ee[p[i]][p[j]])
			{
				int x=find(i),y=find(j);
				if(x!=y)fa[x]=y;
			}
	int cnt=0;
	for(int i=1;i<=k;i++)
		cnt+=!ff[find(i)],ff[find(i)]=1;
	return cnt<=2;
}
inline void dfs_(const int now)
{
	if(now>k)
	{
		if(k>2&&!check())return;
		int ma=0;
		for(int i=1;i<=n;i++)
			if(!f[i])
			{
				int mi=inf;
				for(int j=1;j<=k;j++)
					mi=min(mi,d[i]+d[p[j]]-(d[lca(i,p[j])]<<1));
				ma=max(ma,mi);
			}
		ans=min(ans,ma);
		return;
	}
	for(int i=1;i<=n;i++)
		if(!f[i])p[now]=i,f[i]=1,dfs_(now+1),f[i]=0;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k,idx=0,ans=inf;
		for(int i=1;i<=n;i++)
		{
			h[i]=d[i]=0;
			if(k>2)for(int j=1;j<=n;j++)
				ee[i][j]=0;
		}
		for(int i=1,u,v;i<n;i++)
		{
			cin>>u>>v,add(u,v),add(v,u);
			if(k>2)ee[u][v]=ee[v][u]=1;
		}
		dfs(1,0),dfs_(1),cout<<ans<<endl;
	}
	return 0;
}

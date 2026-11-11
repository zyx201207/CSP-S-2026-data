#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e3+1,L=13;
int u[N],v[N],d[N],dfn[N],s[N],lw[N];
int cost[N][N],n,k,tick;
int fat[N][L];
vector<pair<int,int>>e[N];
vector<int>son[N];
void fil()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
}
int get_lca(int x,int y)
{
	if(d[x]<d[y])swap(x,y);
	int det=d[x]-d[y];
	for(int i=0;i<L;i++)if(det&(1<<i))x=fat[x][i];
	if(x==y)return x;
	for(int i=L-1;i>=0;i--)if(fat[x][i]!=fat[y][i])x=fat[x][i],y=fat[y][i];
	return fat[x][0];
}
void dfs1(int u,int fa=-1)
{
	son[d[u]].emplace_back(u);
	dfn[u]=++tick;
	for(int o=0;o<e[u].size();o++)
	{
		int v=e[u][o].first,p=e[u][o].second;
		if(v!=fa)
		{
			d[v]=d[u]+1;lw[p]=v;
			fat[v][0]=u;
			for(int i=1;i<L;i++)fat[v][i]=fat[fat[u][i-1]][i-1];
			dfs1(v,u);
		}
	}
}
int calc(int u,int x,int rt,int fa=-1)
{
	s[u]=0;
	int la=0;
	for(int o=e[u].size()-1;o>=0;o--)
	{
		int v=e[u][o].first,p=e[u][o].second;
		if(v!=fa)
		{
			int tp=calc(v,x,rt,u);
			if(tp==0)continue;
			if(la==0)la=tp;
			else la=get_lca(la,tp);
		}
	}
	while(!son[d[u]+x].empty())
	{
		int tp=son[d[u]+x].back();
		if(dfn[tp]<dfn[u])break;
		if(la==0)la=tp;
		else la=get_lca(la,tp);
		son[d[u]+x].pop_back();
	}
	if(u==rt)s[u]++;
	else if(la!=0)s[la]++;
	return la;
}
void dfs2(int u,int fa=-1)
{
	for(int o=e[u].size()-1;o>=0;o--)
	{
		int v=e[u][o].first,p=e[u][o].second;
		if(v!=fa)dfs2(v,u),s[u]+=s[v];
	}
}
int qmin(int u,int banned,int fa=-1)
{
	int ans=cost[u][banned];
	for(int o=0;o<e[u].size();o++)
	{
		int v=e[u][o].first,p=e[u][o].second;
		if(v!=fa&&p!=banned)ans=min(ans,qmin(v,banned,u));
	}
	return ans;
}
bool check(int x)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<n;j++)vector<int>().swap(son[j]);
		for(int j=0;j<L;j++)fat[i][j]=0;d[i]=0;
		tick=0;dfs1(i);
		calc(i,x,i);dfs2(i);
		for(int j=1;j<n;j++)
			cost[i][j]=s[i]-s[lw[j]];
	}
	for(int i=1;i<n;i++)
	{
		int p1_min=qmin(u[i],i);
		int p2_min=qmin(v[i],i);
		if(p1_min+p2_min<=k)return 1;
	}
	return 0;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++)
	{
		cin>>u[i]>>v[i];
		e[u[i]].emplace_back(v[i],i);e[v[i]].emplace_back(u[i],i);
	}
	int l=0,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans<<'\n';
}
int main()
{
	fil();
	ios::sync_with_stdio(false);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
}

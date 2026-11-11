#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,k,bj[N],go[N][21],fa[N];
vector<int> g[N]; 
pair<int,int> e[N];
int get(int x)
{
	int cnt=0;
	while(x)
	{
		cnt+=(x&1);
		x>>=1;
	}
	return cnt;
}
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int dep[N];
void dfs(int u,int f)
{
	dep[u]=dep[f]+1;
	go[u][0]=f;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==f) continue;
		dfs(v,u);
	}
}
int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	int jp=dep[u]-dep[v];
	for(int i=20;i>=0;i--)
		if(jp>=(1<<i)) jp-=(1<<i),u=go[u][i];
	if(u==v) return u;
	for(int i=20;i>=0;i--)
		if(go[u][i]!=go[v][i]) u=go[u][i],v=go[v][i];
	return go[u][0];
}
int getdis(int u,int v)
{
	int lc=lca(u,v);
	return dep[u]+dep[v]-2*dep[lc];
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			e[i]={u,v};
		}
		dfs(1,0);
		for(int i=1;i<=20;i++)
			for(int j=1;j<=n;j++)
				go[j][i]=go[go[j][i-1]][i-1];
		int ans=1e9;
		for(int i=0;i<(1<<n);i++)
		{
			if(get(i)!=k) continue;
			for(int j=1;j<=n;j++) bj[j]=0,fa[j]=j;
			vector<int> cs;
			for(int j=1;j<=n;j++) 
				if((i>>(j-1))&1) bj[j]=1,cs.push_back(j);
			for(int j=1;j<n;j++)
			{
				int u=e[j].first,v=e[j].second;
				if(bj[u]&&bj[v])
				{
					u=find(u),v=find(v);
					if(u!=v) fa[u]=v;
				}
			}
			int cnt=0;
			for(int u:cs) if(find(u)==u) cnt++;
			if(cnt>2) continue;
			cnt=0;
			for(int j=1;j<=n;j++)
			{
				if(bj[j]) continue;
				int dj=1e9;
				for(int k:cs) dj=min(dj,getdis(j,k));
				cnt=max(cnt,dj);
			}
			ans=min(ans,cnt);
		} 
		cout<<ans<<"\n";
	}
	return 0;
}

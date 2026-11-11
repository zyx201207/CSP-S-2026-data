#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int C,t,n,k,ans,tr[15],dis[15][15];
bool vis[15],had[15];
vector<int> tab[15];
void dfs2(int u,int p)
{
	for(int v:tab[u])
	{
		if(v==p||!had[v]) continue;
		vis[v]=true;
		dfs2(v,u);
	}
}
void solve()
{
	memset(vis,false,sizeof(vis));
	int cnt=0;
	for(int i=1;i<=k;i++)
	{
		if(vis[tr[i]]) continue;
		vis[tr[i]]=true,cnt++,dfs2(tr[i],0);
	}
	if(cnt>2) return ;
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(had[i]) continue;
		int tmp=inf;
		for(int j=1;j<=k;j++)
		{
			tmp=min(tmp,dis[i][tr[j]]);
		}
		res=max(res,tmp);
	}
	ans=min(ans,res);
}
void dfs1(int st,int lst)
{
	if(st==k)
	{
		solve();
		return ; 
	}
	for(int i=lst+1;i<=n;i++)
	{
		tr[st+1]=i;
		had[i]=true;
		dfs1(st+1,i);
		tr[st+1]=0;
		had[i]=false;
	}
}
void cal(int rt,int u,int p)
{
	for(int v:tab[u])
	{
		if(v==p) continue;
		dis[rt][v]=dis[rt][u]+1;
		cal(rt,v,u);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>t;
	while(t--)
	{
		ans=inf;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			tab[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			tab[u].push_back(v);
			tab[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
		{
			cal(i,i,0);
		}
		dfs1(0,0);
		cout<<ans<<'\n';
	}
	return 0;
}

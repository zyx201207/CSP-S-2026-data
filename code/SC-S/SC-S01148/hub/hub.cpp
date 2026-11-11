#include <bits/stdc++.h>
using namespace std;
const int N=1005;
vector <int> e[N];
int n,k,a[N],res,ct,ans;
bool vis[N],vis2[N];
vector <int> vv[N];
void dfs1(int u,int fr)
{
	vv[ct].push_back(u);
	vis2[u]=1;
	for(int v:e[u])
	{
		if(v==fr) continue;
		if(!vis[v]) continue;
		dfs1(v,u);
	}
}
void dfs2(int u,int fr,int w)
{
	if(vis[u]) w=0;
	res=max(res,w);
	for(int v:e[u])
	{
		if(v==fr) continue;
		dfs2(v,u,w+1);
	}
}
void dfs(int st,int cho)
{
	if(n+1-st+cho<k) return;
	if(cho>k) return;
	if(st>n)
	{
		memset(vis2,0,sizeof vis2);
		ct=0;res=0;
		for(int i=1;i<=k;i++)
			if(!vis2[a[i]]) vv[++ct].clear(),dfs1(a[i],0);
		if(ct>2) return;
		for(int i=1;i<=ct;i++)
			dfs2(vv[i][0],0,0);
		ans=min(ans,res);
	}
	vis[st]=1;a[cho+1]=st;
	dfs(st+1,cho+1);
	vis[st]=0;
	dfs(st+1,cho);
}
int main()
{
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;cin>>u>>v;
			e[u].push_back(v);e[v].push_back(u);
		}
		if(c==7||c<=3)
		{
			ans=n+1;
			dfs(1,0);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
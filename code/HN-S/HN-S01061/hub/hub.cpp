#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+5;
const int NN=55;
int cid,T,n,m,k;
int u,v;
vector<int> ed[N];
bool vis[NN],vis2[NN],bvis[NN];
int fr,bk;
int dis[NN],que[NN];
int a[NN];
int ans=114514;
void dfs2(int u,int fa)
{
	vis2[u]=1;
	for(auto v:ed[u])
	{
		if(v==fa or !vis[v] or vis2[v]) continue;
		dfs2(v,u);
	}
}
int bfs()
{
	int ans=0;
	fr=1,bk=0;
	for(int i=1;i<=n;i++)
		dis[i]=0,bvis[i]=0;
	for(int i=1;i<=k;i++)
		que[++bk]=a[i],bvis[a[i]]=1;
	while(fr<=bk)
	{
		int u=que[fr];
		++fr;
		bvis[u]=1;
		for(auto v:ed[u])
		{
			if(bvis[v]) continue;
			dis[v]=dis[u]+1;
			ans=max(ans,dis[v]);
			que[++bk]=v;
		}
	}
	return ans;
}
bool check()
{
	for(int i=1;i<=n;i++)
		vis2[i]=0;
	int cnt=0;
	for(int i=1;i<=k;i++)
		if(!vis2[a[i]])
		{	
			++cnt;
			dfs2(a[i],0);
		}
	return cnt<=2;
}
void work(int x,int lst)
{
	if(x>k)
	{
		if(!check()) return;
		ans=min(ans,bfs());
		return;
	}
	for(int i=lst+1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1;
			a[x]=i;
			work(x+1,i);
			a[x]=0;
			vis[i]=0;
		}
}
signed main()
{
	freopen("hub.in","r",stdin); 
	freopen("hub.out","w",stdout);
	cin>>cid>>T;
	while(T--)
	{
		ans=114514;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			ed[u].push_back(v);
			ed[v].push_back(u);
		}
		work(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
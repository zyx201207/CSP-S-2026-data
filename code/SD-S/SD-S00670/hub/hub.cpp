#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MSOD
#define READ_IN_FILE
using namespace std;
const int N=2e5+10,P=998244353,inf=0x3f3f3f3f;
int n,m,cnt,dis[N],ans;
vector<int>e[N];
vector<int>bc;
bitset<N>vis,fl;
queue<int>q;
void dfs(int u,int fa)
{
	if(vis[u]&&!vis[fa])cnt++;
	for(auto v:e[u])
		if(v!=fa)dfs(v,u);
}
int bfs()
{
	int res=0;
	fl.reset();
	for(auto v:bc)q.push(v),fl[v]=1,dis[v]=0;
	while(q.size())
	{
		auto u=q.front();q.pop();
		for(auto v:e[u])
		{
			if(fl[v])continue;
			fl[v]=1;
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}
	for(int i=1;i<=n;i++)res=max(res,dis[i]);
	return res;
}
void ddfs(int c,int lst)
{
	if(c==m+1)
	{
		cnt=0;
		dfs(1,0);
		if(cnt>2)return;
		ans=min(ans,bfs());
		return;
	}
	for(int i=lst+1;i<=n;i++)
	{
		bc.push_back(i);vis[i]=1;
		ddfs(c+1,i);
		bc.pop_back();vis[i]=0;
	}
}
void solve()
{
	cin>>n>>m;ans=inf;
	for(int i=1;i<=n;i++)e[i].clear();
	bc.clear();
	for(int i=1;i<n;i++)
	{
		int u,v;cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	ddfs(1,0);
	cout<<ans<<'\n';
	return;
}
signed main()
{
	FAST
#ifdef READ_IN_FILE
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
#endif
	int _C_,_T_=1;
#ifdef MSOD
	cin>>_C_>>_T_;
#endif
	while(_T_--)solve();
	return 0;
}

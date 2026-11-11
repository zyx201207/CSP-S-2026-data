#include<bits/stdc++.h>
#define ll long long
#define pr(x) pair<x,x>
#define up(i,j,k,l) for(int i=j;i<=k;i+=l)
#define down(i,j,k,l) for(int i=j;i>=k;i-=l)
using namespace std;
const int N=1e3+10,INF=1e9;
int n,k;
vector<int> g[N];
void addg_edge(int u,int v)
{
	g[u].push_back(v);
	g[v].push_back(u);
	return;
} 
int fa[N];
void dfs(int u,int fq)
{
	fa[u]=fq;
	for(auto v:g[u]){
		if(v!=fq){
			dfs(v,u);
		}
	}
	return;
}
struct DSU{
	int ft[N];
	void init()
	{
		up(i,1,n,1){
			ft[i]=i;
		}
		return;
	}
	int fd(int x)
	{
		return (ft[x]==x?x:ft[x]=fd(ft[x]));
	}
	void mg(int x,int y)
	{
		ft[fd(x)]=fd(y);
		return;
	}
};
DSU dsu;
bool vis[N];
vector<int> tmp;
int dis[N];
queue<int> q;
void bfs()
{
	up(i,1,n,1){
		dis[i]=n+1;
	}
	for(auto bl:tmp){
		q.push(bl);
		dis[bl]=0;
	}
	int u;
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(auto v:g[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return;
}
int ans;
void ch(int tot)
{
	if(tot==0){
		dsu.init();
		for(auto bl:tmp){
			if(vis[fa[bl]]){
				dsu.mg(bl,fa[bl]);
			}
		}
		int ltk=0;
		up(i,1,n,1){
			if(vis[i] && i==dsu.fd(i)){
				ltk++;
			}
		}
		if(ltk<=2){
			bfs();
			int res=0;
			up(i,1,n,1){
				res=max(res,dis[i]);
			}
			ans=min(ans,res);
		}
		return;
	}
	up(i,1,n,1){
		if(vis[i]==false){
			vis[i]=true;
			tmp.push_back(i);
			ch(tot-1);
			tmp.pop_back();
			vis[i]=false;
		}
	}
	return;
}
void init()
{
	up(i,1,n,1){
		g[i].clear();
	}
	return;
}
void solve()
{
	cin>>n>>k;
	init();
	int u,v;
	up(i,1,n-1,1){
		cin>>u>>v;
		addg_edge(u,v);
	}
	dfs(1,0);
	ans=INF;
	ch(k);
	cout<<ans<<endl;
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,_=1;
	cin>>c>>_;
	up(i,1,_,1){
		solve();
	}
	return 0;
}


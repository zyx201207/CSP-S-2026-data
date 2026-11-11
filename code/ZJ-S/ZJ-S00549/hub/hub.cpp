#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int c,t,n,m,ans,maxx,res,f;
bool vis[105];
vector<int>g[N];
void df(int u,int fa)
{
	for(auto v:g[u])
	{
		if(v==fa) continue;
		df(v,u);
		if(!vis[u]&&vis[v]) f++;
	}
}
void dfs(int u,int fa,int sd)
{
	if(vis[u])
	{
		res=min(res,sd);
		return ;
	}
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u,sd+1);
	}
}
void qp(int k,int cn)
{
	if(k==n+1)
	{
		if(cn<m) return ;
//		for(int i=1;i<=n;i++) cout<<vis[i]<<' ';
//		cout<<'\n';
		maxx=f=0;
		df(1,0);
		if(vis[1]) f++;
		if(f>2) return ;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) continue;
//			cout<<i<<' ';
			res=1e18;
			dfs(i,0,0);
			maxx=max(maxx,res);
		}
//		cout<<'\n';
		ans=min(ans,maxx);
		return ;
	}
	if(cn<m)
	{
		vis[k]=1;
		qp(k+1,cn+1);
	}
	vis[k]=0;
	qp(k+1,cn);
}
void solve1()
{
	ans=1e18;
	qp(1,0);
	cout<<ans<<'\n';
}
void solve2()
{
	if(m==n) cout<<0<<'\n';
	else if(m>n/2) cout<<1<<'\n';
	else
	{
		int k=n/2;
		k=(k+1)/2;
		m=(m+1)/2;
		cout<<(k-m+1)/2+1<<'\n';
	}
}
void solve3()
{
	cout<<1<<'\n';
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1,u,v;i<n;i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(c<=6) solve1();
		else if(c<=14&&c>=13) solve2();
		else solve3();
		for(int i=1;i<=n;i++) g[i].clear();
	}
	return 0;
}
/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9


*/

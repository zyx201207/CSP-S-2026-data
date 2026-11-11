#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
#define BUG cout<<"BUG"<<endl;
const int N = 100;
using namespace std;
inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
		x = x*10+ch-'0',ch = getchar();
	return x*f;
}
int n,k;
bool vis[N];
int fa[N];
int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int dist[N][N];
int ans = INF;
vector<int> g[N];
void dfs(int x,int num)
{
	if(num == k)
	{
		for(int i = 1;i<=n;++i)
			if(vis[i])
				fa[i] = i;
		for(int i = 1;i<=n;++i)
		{
			if(!vis[i]) continue;
			for(auto j : g[i])
			{
				if(!vis[j]) continue;
				int x = find(i),y = find(j);
				if(x == y) continue;
				fa[x] = y;
			}
		}	
		int cnt = 0;
		for(int i = 1;i<=n;++i)
			if(vis[i] && fa[i] == i)
				cnt++;
		if(cnt > 2) return ;
		int mx = 0;
		for(int i = 1;i<=n;++i)
		{
			int mn = INF;
			for(int j = 1;j<=n;++j)
			{
				if(vis[j])
				{
					mn = min(mn,dist[i][j]);
				}
			}
			mx = max(mx,mn);
		}
		ans = min(ans,mx);
		return ;
	}
	if(x == n+1) return ;
	vis[x] = 1;
	dfs(x+1,num+1);
	vis[x] = 0;
	dfs(x+1,num);
}
void d(int u,int fa,int c)
{
	for(auto v : g[u])
	{
		if(v == fa) continue;
		dist[c][v] = dist[c][u]+1;
		d(v,u,c);
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c = read(),T = read();
	while(T--)
	{
		n = read(),k = read();
		ans = INF;
		for(int i = 1;i<n;++i)
		{
			int x = read(),y = read();
			g[x].push_back(y);
			g[y].push_back(x);
		}
		for(int i = 1;i<=n;++i)
			d(i,0,i);
		
		dfs(1,0);
		
		cout<<ans<<endl;
		for(int i = 1;i<=n;++i)
			g[i].clear();
	}
	return 0;
}



#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long N = 1e6;
long long c,t,n,k,u,v,ans,dis[N+10];
vector<long long> e[N+10];
bool build[N+10],vis[N+10];
void dfs2(long long x)
{
	for(auto nxt : e[x])
	{
		if(!vis[nxt] && build[nxt])
		{
			vis[nxt] = 1;
			dfs2(nxt);
		}
	}
}
void dfs(long long x,long long cnt)
{
	if(cnt>k)    return ;
	if(x>n)
	{
		if(cnt<k)    return ;
		long long lt = 0;
		for(int i = 1; i <= n; i++)    vis[i] = 0;
		for(int i = 1; i <= n; i++)
		{
			if(!vis[i] && build[i])
			{
				vis[i] = 1;
				dfs2(i);
				lt++;
			}
		}
		if(lt>2)    return ;
		for(int i = 1; i <= n; i++)
		{
			if(build[i])    dis[i] = 0;
			else    dis[i] = INF;
		}
		for(int i = 1; i <= n; i++)
		{
			if(dis[i]==0)    continue;
			for(int j = 1; j <= n; j++)    vis[j] = 0;
			queue<pair<long long,long long> > q;
			q.push(make_pair(i,0));
			vis[i] = 1;
			while(!q.empty())
			{
				if(dis[i]!=INF)    break;
				pair<long long,long long> cur = q.front();
				q.pop();
				for(auto nxt : e[cur.first])
				{
					if(vis[nxt])    continue;
					if(build[nxt])
					{
						dis[i] = cur.second+1;
						break;
					}
					vis[nxt] = 1;
					q.push(make_pair(nxt,cur.second+1));
				}
			}
		}
		long long mx = 0;
		for(int i = 1; i <= n; i++)    mx = max(mx,dis[i]);
		ans = min(ans,mx);
		return ;
	}
	build[x] = 1;
	dfs(x+1,cnt+1);
	build[x] = 0;
	dfs(x+1,cnt);
}
void solve()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)    e[i].clear();
	for(int i = 1; i < n; i++)
	{
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	ans = INF;
	dfs(1,0);
	cout << ans << "\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--)    solve();
	return 0;
}

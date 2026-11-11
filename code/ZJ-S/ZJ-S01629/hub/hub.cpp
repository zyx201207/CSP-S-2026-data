#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000006;
int n;
int k;
int dis[MAXN];
bool vis[MAXN];
vector<int> vec[MAXN];
void dfs1(int now, int fa, long long sta)
{
	vis[now] = true;
	for(int v : vec[now])
	{
		if(v == fa)
		{
			continue;
		}
		if(vis[v])
		{
			continue;
		}
		if(!((sta>>(v-1))&1))
		{
			continue;
		}
		dfs1(v,now,sta);
	}
}
bool check(long long sta)
{
	int tmp = 0;
	for(int i = 1; i<=n; i++)
	{
		if((sta>>(i-1))&1)
		{
			tmp++;
		}
	}
	if(tmp!=k)
	{
		return false;
	}
	int cnt = 0;
	for(int i = 1; i<=n; i++)
	{
		vis[i] = 0;
	}
	for(int i = 1; i<=n; i++)
	{
		if(!vis[i] && ((sta>>(i-1))&1))
		{
			dfs1(i,0,sta);
			cnt++;
		}
		if(cnt>2)
		{
			return false;
		}
	}
	return true;
}
int calc(long long sta)
{
	for(int i = 1; i<=n; i++)
	{
		dis[i] = 0x3f3f3f3f;
		vis[i] = 0;
	}
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
	for(int i = 1; i<=n; i++)
	{
		if((sta>>(i-1))&1)
		{
			dis[i] = 0;
			q.push(make_pair(0,i));
		}
	}
	while(!q.empty())
	{
		int u = q.top().second;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u] = true;
		for(int v : vec[u])
		{
			if(dis[v]>dis[u]+1)
			{
				dis[v] = dis[u]+1;
				q.push(make_pair(dis[v],v));
			}
		}
	}
	int res = 0;
	for(int i = 1; i<=n; i++)
	{
		res = max(res,dis[i]);
	}
	return res;
}
void work()
{
	cin>>n>>k;
	for(int i = 1; i<=n; i++)
	{
		vec[i].clear();
	}
	for(int i = 1; i<n; i++)
	{
		int u;
		int v;
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	int res = INT_MAX;
	for(long long sta = 0; sta<(1ll<<n); sta++)
	{
		if(check(sta))
		{
			res = min(res,calc(sta));
		}
	}
	cout<<res<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c;
	int t;
	cin>>c>>t;
	while(t--)
	{
		work();
	}
	return 0;
}

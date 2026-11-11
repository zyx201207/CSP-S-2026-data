#include<bits/stdc++.h>
using namespace std;
#define int long long

vector <int> adj[1000005];
int n,k;
int ans = 1e18;
bool ok[1000005];
bool okk[1000005];

void dfss(int now)
{
	for(int i = 0;i < adj[now].size();i++)
	{
		int v = adj[now][i];
		if(ok[v] && !okk[v])
		{
			okk[v] = 1;
			dfss(v);
		}
	}
	return;
}

bool checkk()
{
	for(int i = 1;i <= n;i++)
	{
		okk[i] = 0;
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		if(ok[i] && !okk[i])
		{
			cnt++;
			okk[i] = 1;
			dfss(i);
		}
	}
	return cnt <= 2;
}

int dfsss(int now,int deep)
{
	int ma = 0;
	int cnt = 0;
	for(int i = 1;i < adj[now].size();i++)
	{
		int v = adj[now][i];
		if(!okk[v])
		{
			cnt++;
			okk[v] = 1;
			ma = max(ma,dfsss(v,deep + 1));
		}
	}
	if(cnt == 0)
	{
		if(ok[now])
		{
			return 0;
		}
		return deep;
	}
	return ma;
}

void check()
{
	int ma = 0;
	if(!checkk())
	{
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(!ok[i])
		{
			for(int j = 1;j <= n;j++)
			{
				okk[j] = 0;
			}
			okk[i] = 1;
			ma = max(ma,dfsss(i,0));
		}
	}
	ans = min(ans,ma);
}

void dfs(int deep,int xuan)
{
	if(deep == n + 1)
	{
		if(xuan == k)
		{
			check();
		}
		return;
	}
	ok[deep] = 0;
	dfs(deep + 1,xuan);
	ok[deep] = 1;
	dfs(deep + 1,xuan + 1);
	return;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1;i <= n;i++)
		{
			adj[i].clear();
		}
		for(int i = 1;i < n;i++)
		{
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		ans = 1e18;
		dfs(1,0);
		cout << ans << '\n';
	}
	return 0;
}
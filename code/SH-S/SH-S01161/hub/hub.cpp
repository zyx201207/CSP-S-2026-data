#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5, M = 25;
ll C, T, n, m, u, v, f[N][M], dep[N], ans, cnt;
bool built[N], vis[N];
vector<ll> e[N];
void dfs(ll u, ll fa)
{
	dep[u] = dep[fa] + 1;
	f[u][0] = fa;
	for(int i = 1; i <= 20; i++)
	{
		f[u][i] = f[f[u][i - 1]][i - 1];
	}
	for(auto i : e[u])
	{
		if(i != fa)
		{
			dfs(i, u);
		}
	}
}
ll lca(ll a, ll b)
{
	if(dep[a] < dep[b])
	{
		swap(a, b);
	}
	for(int i = 20; i >= 0; i--)
	{
		if(dep[f[a][i]] >= dep[b])
		{
			a = f[a][i];
//			cout << "!" << a;
		}
	}
	if(a == b)
	{
		return a;
	}
	for(int i = 20; i >= 0; i--)
	{
		if(f[a][i] != f[b][i])
		{
			a = f[a][i];
			b = f[b][i];
//			cout << "?" << a << " " << b;
		}
	}
	return f[a][0];
}
ll dis(ll a, ll b)
{
	ll tmp = lca(a, b);
	return (dep[a] - dep[tmp]) + (dep[b] - dep[tmp]);
}
void DFS(ll u)
{
	vis[u] = 1;
	for(auto i : e[u])
	{
		if(!vis[i] && built[i])
		{
			DFS(i);
		}
	}
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	scanf("%lld%lld", &C, &T);
	while(T--)
	{
		ans = 1e18;
		scanf("%lld%lld", &n, &m);
		for(int i = 1; i <= n; i++)
		{
			e[i].clear();
		}
		for(int i = 1; i < n; i++)
		{
			scanf("%lld%lld", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1, 0);
//		cout << lca(3, 5) << " " << dis(3, 5) << " ";
		for(int i = 0; i < (1 << n); i++)
		{
			vector<ll> V;
			cnt = 0;
			for(int j = 1; j <= n; j++)
			{
				if(i & (1 << (j - 1)))
				{
					cnt++;
					built[j] = 1;
					V.push_back(j);
				}
				else
				{
					built[j] = 0;
				}
				vis[j] = 0;
			}
			if(cnt != m)
			{
				continue;
			}
			cnt = 0;
			for(auto j : V)
			{
				if(!vis[j])
				{
					DFS(j);
					cnt++;
				}
			}
			if(cnt > 2)
			{
				continue;
			}
//			cout << "!" << i << " ";
			ll maxn = 0;
			for(int j = 1; j <= n; j++)
			{
				ll minn = 1e18;
				for(auto k : V)
				{
					minn = min(minn, dis(j, k));
				}
				maxn = max(minn, maxn);
//				cout << minn << " ";
			}
			ans = min(ans, maxn);
		}
		cout << ans << endl;
	}
	return 0;
}

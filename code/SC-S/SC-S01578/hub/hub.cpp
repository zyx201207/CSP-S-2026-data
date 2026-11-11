#include <bits/stdc++.h>
using namespace std;
#define int long long
#define eb emplace_back
#define ep emplace
#define pii pair <int, int>
#define fi first
#define se second
constexpr int MAXN = 5005;
int c, t;
int n, k;
vector <int> adj[MAXN];
int dist[MAXN][MAXN];
int cho[MAXN];
bool vis[MAXN];
bool check ()
{
	memset(vis, 0, sizeof vis);
	int cnt = 0;
	for (int i = 0 ; i < k ; i ++)
	{
		if (not vis[i])
		{
			cnt ++;
			vis[i] = 1;
			queue <int> q;
			q.ep(cho[i]);
			while (not q.empty())
			{
				int ls = q.front();
				q.pop();
				for (int it : adj[ls])
				{
					int pd = -1;
					for (int o = 0 ; o < k ; o ++)
					{
						if (cho[o] == it)
						{
							pd = o;
							break;
						}
					}
					if (pd != -1 and vis[pd] == 0)
					{
						vis[pd] = 1;
						q.ep(cho[pd]);
					}
				}
			}
			int pd = 0;
			for (int o = 0 ; o < k ; o ++)
			{
				if (vis[o])
				{
					pd ++;
				}
			}
			if (cnt <= 2 and pd == k)
			{
				return 1;
			}
		}
	}
	return 0;
}
int ans;
int dep[MAXN];
void dfs (int st, int js)
{
	if (js == k)
	{
		if (check())
		{
			int ss = 0;
			queue <pii> q;
			memset(dep, 0x3f, sizeof dep);
			for (int i = 0 ; i < k ; i ++)
			{
				q.ep(cho[i], 0);
				dep[cho[i]] = 0;
			}
			while (not q.empty())
			{
				auto ww = q.front();
				q.pop();
				for (auto it : adj[ww.fi])
				{
					if (it != ww.se)
					{
						dep[it] = min(dep[it], dep[ww.fi] + 1);
						q.ep(it, ww.fi);
					}
				}
			}
			for (int i = 1 ; i <= n ; i ++)
			{
				ss = max(ss, dep[i]);
			}
			ans = min(ss, ans);
		}
		return ;
	}
	for (int i = st ; i <= n ; i ++)
	{
		cho[js] = i;
		dfs(i + 1 , js + 1);
	}
}
signed main ()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t --)
	{
		cin >> n >> k;
		memset(dist, 0x3f, sizeof dist);
		for (int i = 1 ; i <= n ; i ++)
		{
			adj[i].clear();
			dist[i][i] = 0;
		}
		for (int i = 1 ; i < n ; i ++)
		{
			int uu, vv;
			cin >> uu >> vv;
			adj[uu].eb(vv);
			adj[vv].eb(uu);
			dist[uu][vv] = dist[vv][uu] = 1;
		}
		for (int kk = 1 ; kk <= n ; kk ++)
		{
			for (int i = 1 ; i <= n ; i ++)
			{
				for (int j = 1 ; j <= n ; j ++)
				{
					if (i != j and j != kk and i != kk)
					{
						dist[i][j] = min(dist[i][j], dist[i][kk] + dist[kk][j]);
					}
				}
			}
		}
		ans = 0x3f3f3f3f;
		dfs(1, 0);
		cout << ans << endl;	
	}
	return 0;
}//18:28极限写完 

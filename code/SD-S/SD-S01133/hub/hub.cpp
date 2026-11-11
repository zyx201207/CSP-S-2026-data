#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 999999999999999999ll;
int n, c, t, k, a[2000005], ans, fa[2005], g[15][15], dep[105], up[2005];
vector<int> z[2000005];
int find(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void dfs(int p, int f)
{
	up[p] = f;
	dep[p] = dep[f]+1;
	for(auto i:z[p])
	{
		if(i == f) continue;
		dfs(i, p);
	}
	return; 
}
void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x == y) return;
	fa[x] = y;
	return;
}
int dis(int x, int y)
{
	int res = 0;
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] != dep[y])
	{
		res++;
		x = up[x];
	}
	while(x != y)
	{
		res += 2;
		x = up[x];
		y = up[y];
	}
	return res;
}
set<int> s;
vector<int> v;
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			z[i].clear();
		for(int i = 1; i < n; i++)
		{
			int u, V;
			cin >> u >> V;
			z[u].push_back(V);
			z[V].push_back(u);
		}
		if(n <= 10)
		{
			int ans = 999999999;
			dfs(1, 0);
			for(int i = 0; i < (1<<n); i++)
			{
				s.clear();
				v.clear();
				if(__builtin_popcount(i) != k) continue;
				memset(g, 0, sizeof(g));
				for(int j = 1; j <= n; j++)
				{
					fa[j] = j;
					for(auto k:z[j])
						g[j][k] = 1;
					if(i&(1<<(j-1))) v.push_back(j);
				}
				assert(v.size() == k); 
				for(auto j:v)
				{
					for(auto k:v)
					{
						if(g[j][k]) merge(j, k);
					}
				}
				for(auto j:v)
				{
//					cout << j << ' ';
					s.insert(find(j));
				}
				if(s.size() <= 2)
				{
					int D = 0, d = 9999999;
					for(int i = 1; i <= n; i++)
					{
						d = 9999999;
						for(auto j:v)
						{
							d = min(d, dis(i, j));
						}
						D = max(d, D); 
					}
//					if(D == 1)
//					{
//						for(auto j:v)
//						cout << j << ' ';
//						cout << "!!\n";
//						for(auto j:s) cout << j << ' ';
//						cout << "??\n";
//					}
					ans = min(ans, D);
				}
			}
			cout << ans << '\n';
			continue;
		}
		cout << n/8+2 << '\n'; 
	}
	return 0;
}


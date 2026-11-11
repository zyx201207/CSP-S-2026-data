#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll p, n, d, a[500009], dummy, val[500009], dep[500009], ans;
bool vis[500009];
vector<ll> graph[500009];
void clear ()
{
//	remind();
	for (int i = 0; i < n; i++)graph[i].clear();
	ans = 0;
}
queue<ll> q;
int main ()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//migration migration move from station to station
	cin >> dummy >> p;
	while (p--)
	{
		clear();
		cin >> n >> d;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n && a[j]-a[i] <= d; j++)
			{
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
		for (int i = 0; i < n; i++)
		{
			memset (vis, 0, sizeof vis);
			memset (val, 0, sizeof val);
			memset (dep, 0, sizeof dep);
			val[i] = 1;
			dep[i] = 1;
			q.push(i);
			while (!q.empty())
			{
				ll u = q.front();
				q.pop();
				if (vis[u]) continue;
				vis[u] = true;
				if (val[u] == 2) 
				{
					++ans;
//					cout << i << " " << u << endl;
				}
				for (ll vx = 0; vx < graph[u].size(); vx++)
				{
					ll v = graph[u][vx];
					if (vis[v])continue;
					if (dep[v] != dep[u]+1 && dep[v] != 0) continue;
					val[v] += val[u];
					dep[v] = dep[u]+1;
					q.push(v);
				}
			}
		}
		cout << ans/2 << endl;
	}
	return 0;
}

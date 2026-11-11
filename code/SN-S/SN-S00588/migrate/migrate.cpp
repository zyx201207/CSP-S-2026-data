#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

#define ll long long
#define pll pair<ll, ll>

int N; ll d;
ll Xa[2000010];
vector<ll>g[2000010];
priority_queue<pll, vector<pll>, greater<pll> >q;
ll dis[2000010], vis[2000010];
ll cnt[2000010];

void solve()
{
	memset(dis, 127, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	memset(Xa, 0, sizeof(Xa));
	for(int i = 1; i <= N; i++)
		g[i].clear();
	cin >> N >> d;
	for(int i = 1; i <= N; i++) cin >> Xa[i];
	for(int i = 1; i <= N - 1; i++)
		for(int j = i + 1; j <= N; j++)
			g[i].push_back(j);
	ll ans = 0;
	for(int p = 1; p <= N; p++)
	{
		memset(dis, 127, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		memset(cnt, 0, sizeof(cnt));
		q.push({0, p}); dis[p] = 0;
		while(!q.empty())
		{
			ll x = q.top().second;
			q.pop();
			if(vis[x]) continue;
			vis[x] = 1;
			for(int i = 0; i < g[x].size(); i++)
			{
				ll y = g[x][i];
				if(dis[x] + 1 < dis[y] && abs(Xa[x] - Xa[y]) <= d)
				{
					dis[y] = dis[x] + 1;
					q.push({dis[y], y});
					cnt[y] = 1;
				}
				else if(dis[x] + 1 == dis[y]) cnt[y]++;
			}
		}
		for(int i = p; i <= N; i++)
			if(cnt[i] == 2) ans++;
	}
	cout << ans << '\n';
} 

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while(T--)
		solve();
	return 0;
}


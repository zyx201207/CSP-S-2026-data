#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int MX = 2e6 + 5;
const int inf = 1e18;

int dis[MX];
int cnt[MX];
int a[MX];
int n,d;

void dij(int s)
{
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.push({0,s});
	fill(dis + 1,dis + MX + 1,inf);
	cnt[s] = 1;
	dis[s] = 0;
	while(!q.empty())
	{
		int u = q.top().second;
		int du = q.top().first;
		q.pop();
		if(du > dis[u]) continue;
		for(int v = u + 1;v <= n;v++)
		{
			int w = abs(a[u] - a[v]);
			if(w == 0) continue;
			if(w > d) break;
			if(dis[u] + 1 < dis[v])
			{
				cnt[v] = cnt[u];
				dis[v] = dis[u] + 1;
				q.push({dis[v],v});
			}
			else if(dis[u] + 1 == dis[v])
			{
				cnt[v] ++;
			}
		}
	}
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		int x,pre;
		bool f = 1;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
			x = a[i] - a[i - 1];
			if(i >= 3)
			{
				if(x != pre) f = 0;
			}
			pre = x;
		}
		if(f)
		{
			if(d >= 2 * x) cout << n - 3 << '\n';
			else cout << 0 << '\n';
			continue;
		}
		int ans = 0;
		for(int i = 1;i < n;i++)
		{
			dij(i);
			for(int j = i + 1;j <= n;j++)
			{
				if(cnt[j] == 2)
				{
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

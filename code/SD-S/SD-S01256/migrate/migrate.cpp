#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 2;
int c , t , n , pos , step[5005], cnt[5005];
ll d , x[N] , ans;
vector <int> G[5005];
queue <int> q;
void bfs()
{
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0;i < int(G[u].size());i ++)
		{
			int v = G[u][i];
			if  (step[v] == step[u] + 1)
				cnt[v] += cnt[u];
			else if (!step[v]) step[v] = step[u] + 1 , q.push(v) , cnt[v] = cnt[u];
		}
	}
}
void solve()
{
	cin >> n >> d;
	for (int i = 1;i <= n;i ++) cin >> x[i];
	if  (n <= 3 || x[n] - x[1] <= d)
	{
		cout << 0 << "\n";
		return;
	}
	if (c == 11 || c == 12)
	{
		if  (d <= x[2] - x[1])
		{
			cout << 0 << "\n";
			return;
		}
		ll k = 2ll * (d / (x[2] - x[1])) - 1;
		cout << max(0ll , n - k) << "\n";
		return;
	}
	/*
	if  (c == 13 || c == 14)
	{
		int pos = lower_bound(x + 1 , x + 1 + n , x[1] + d) - x;
		if  (x[pos] > x[1] + d) -- pos;
		if  (pos == 2)
		{
			cout << 0 << "\n";
			return;
		}
		int pos1 = lower_bound(x + pos + 1 , x + 1 + n , x[pos - 1] + d) - x;
		if  (x[pos1] > x[pos - 1] + d || pos1 == n + 1) -- pos1;
		int pos2 = lower_bound(x + pos + 1 , x + 1 + n , )
		cout << pos1 - pos << "\n";
		return;
	}
	*/
	if  (c <= 10)
	{
		for (int i = 1;i < n;i ++)
		{
			int pos = lower_bound(x + 1 , x + 1 + n , x[i] + d) - x;
			if  (pos == n + 1 || x[pos] > x[i] + d) -- pos;
			for (int j = i + 1;j <= pos;j ++)
				G[i].push_back(j);
		}
		ans = 0;
		for (int i = 1;i <= n;i ++)
		{
			q.push(i);
			memset(step , 0 , sizeof(step));
			memset(cnt , 0 , sizeof(cnt));
			cnt[i] = 1;
			bfs();
			for (int j = i + 1;j <= n;j ++)
				if  (cnt[j] == 2)
					++ ans;
		}
		cout << ans << "\n";
		for (int i = 1;i <= n;i ++) G[i].clear();
		return;
	}
	
}
int main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out", "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t --) solve();
	return 0;
}

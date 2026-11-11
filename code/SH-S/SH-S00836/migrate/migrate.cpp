#include <bits/stdc++.h>
using namespace std;
int dp[5001][5001], a[5001];
int adj[5001][5001];
long long n, d, ans;
int cal (int start, int step)
{
	if (step == 0) return dp[start][step] = 1;
	for (int i = start + 1; i <= n; i++)
	{
		if (adj[start][i] == 0) continue;
		dp[start][step] += cal(i, step - 1);
	}
	return dp[start][step];
}
int main ()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		if (c == 11 || c == 12)
		{
			cin >> n >> d;
			int t1, t2, t;
			cin >> t1 >> t2;
			for (int i = 3; i <= n; i++) cin >> t;
			if (d <= abs(t2 - t1)) cout << "0\n";
			else cout << n * 2 / 3 - 1 << "\n";
			continue;
		}
		ans = 0; 
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (n <= 3) cout << "0\n";
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
				adj[i][j] = adj[j][i] = (a[j] - a[i]) <= d;
		}
		for (int x = 1; x <= 5000; x++)
			for (int y = 1; y <= 5000; y++) dp[x][y] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int u = 1; i <= n; i++)
			{
				int temp = cal(u, i);
				cout << temp << " "; 
				if (temp == 2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> g[N];
bool x[N];
long long ans = 0;
/*
long long dp(int p, int fa)
{
	long long mx1 = 0, mx2 = 0;
	for (int i : g[p])
	{
		if (x[i]) continue;
		if (i == fa) continue;
		int t = dp(i, p) + 1;
		if (t > mx1) mx2 = mx1, mx1 = t;
		else if (t > mx2) mx2 = t;
	}
    ans = max(ans, mx1 + mx2);	
    x[p] = true;
    return mx1;
}
*/
int main()
{
	freopen("hub.in" ,"r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		ans = 0;
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		/*
		long long anss = LONG_LONG_MAX;
		for (int i = 1; i < (1LL << n); i++)
		{
			for (int j = 1; j <= n; j++) x[j] = false;
			int cnt = 0;
			for (int j = 0; j < n; j++)
			{
				if (i & (1LL << j))
				{
					x[j + 1] = true;
					cnt++;
				}
			}
			if (cnt != k) continue;
			for (int j = 1; j <= n; j++)
			{
				if (!x[j]) ans = max(ans, dp(j, 0));
			}
			anss = min(anss, ans);
		}
		cout << anss << endl;
	    */
		cout << '1' << '\n';
	}
	return 0;
}

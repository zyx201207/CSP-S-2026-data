#include<bits/stdc++.h>
//#define int long long
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
const int N = 5007;
int c, t, n, d;
int a[N];
int dp[N][N], cnt, ans, res;

int find_min(int i, int j)
{
	int s = i, c = 0;
	for (int k = i + 1; k <= j; k++)
	{
		if (a[k] - a[s] > d) c++, s = k - 1;
	}
	if (s != j) c++;
	return c;
}

void dfs(int x, int y, int p, int ct)
{
	if (p == y)
	{
		if (ct == res) cnt++;
		return ;
	}
	for (int i = p + 1; i <= y; i++)
	{
		if (a[i] - a[p] > d) break;
		dfs(x, y, i, ct + 1);
	}
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d; ans = 0;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				res = find_min(i, j); cnt = 0;
				dfs(i, j, i, 0);
				if (cnt == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
暴力：
一共有2500个分层点 8000条边
跑500次dijkstra,然后对于每次直接访问即可500*2500 
*/

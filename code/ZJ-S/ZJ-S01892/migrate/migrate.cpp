#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
int c, t;
int d;
int a[N];
ll ans;
int check(int u, int v)
{
	if (a[v] - a[u] % d != 0) return 1;
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	for (int T = 1; T <= t; T++)
	{
		ans = 0;
		int n;
		scanf("%d%d", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (i == j) continue;
				if (check(i, j))
					ans++;
			}
		cout << ans << endl;
	}
	return 0;
}

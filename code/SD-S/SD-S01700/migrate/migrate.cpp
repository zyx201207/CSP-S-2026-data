#include<bits/stdc++.h>
using namespace std;
#define maxn 2000005
int c, T;
int w[maxn];
void solve()
{
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	int ans = 0;
	for (int l = 1; l <= n; l++)
	{
		for (int r = 1; r <= n; r++)
		{
			int posl = lower_bound(w + 1, w + n + 1, l) - w;
			int posr = lower_bound(w + 1, w + n + 1, r) - w;
			int pos = posr - posl - 1;
			if (pos == 2)
				ans ++;
		}
	}
	cout << ans << endl;
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> T;
	while (T--)
		solve();
	return 0;
}

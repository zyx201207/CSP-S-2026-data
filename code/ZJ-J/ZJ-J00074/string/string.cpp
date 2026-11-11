#include <bits/stdc++.h>
using namespace std;
namespace Main
{
	int n;
	int a[200001];
	char c[200001];
	inline int ra(const int &pos)
	{
		return a[n + 1 - pos];
	}
	inline int rc(const int &pos)
	{
		return c[n + 1 - pos];
	}
	long long ans;
	int main()
	{
		freopen("string.in", "r", stdin);
		freopen("string.out", "w", stdout);
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i] >> c[i];
		for (int tt /*res*/ = 1, t /*src*/ = 1, sy = a[1]; tt <= n; ++tt)
		{
			long long used = 0;
			while (sy < ra(tt) - used)
			{
				ans += (c[t] != rc(tt)) * sy;
				used += sy;
				sy = a[++t];
				// cout << t << ' ' << tt << ' ' << a[t] << ' ' << ra(tt) << ' ' << used << ' ' << sy << '\n';
			}
			// sy + used > ra(tt)
			// (sy=)5 + (used=)2 > 3
			ans += (c[t] != rc(tt)) * (ra(tt) - used);
			sy = sy + used - ra(tt);
			// cout << t << '\n';
		}
		cout << ans / 2 << '\n';
		return 0;
	}
}
int main()
{
	return Main::main();
}
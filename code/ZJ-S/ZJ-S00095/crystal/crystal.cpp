#include <bits/stdc++.h>
using namespace std;
namespace Main
{
	int n, m;
	int a[500001];
	int qzh[500001];
	bool ok(const int &x)
	{
		for (int i = 1; i + x - 1 <= n; ++i)
		{
			const int s /* = sum_{k = i ... (i + x - 1)}a[i + x - 1] - a[k] = a[i + x - 1] * x - sum{ k = i ... i + x - 1}a[k] */ = a[i + x - 1] * x - (qzh[i + x - 1] - qzh[i - 1]);
			// cout << x << ' ' << i << ' ' << s << '\n';
			if (s <= m)
				return true;
		}
		return false;
	}
	int main()
	{
		freopen("crystal.in", "r", stdin);
		freopen("crystal.out", "w", stdout);
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; ++i)
			qzh[i] = qzh[i - 1] + a[i];
		int l = 1, r = n;
		while (l < r)
		{
			int mid = ((l + r + 1) >> 1);
			if (ok(mid))
				l = mid;
			else
				r = mid - 1;
		}
		cout << l << '\n';
		return 0;
	}
}
int main()
{
	return Main::main();
}
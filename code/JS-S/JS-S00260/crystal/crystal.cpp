#include <bits/stdc++.h>
#define int long long
using namespace std;

// 45pts

int n, m;
vector<int> a;

inline bool check(int k)
{
	int us = 0;
	for (int j = 0; j < k - 1; j++)
	{
		us += a[k - 1] - a[j];
	}
	if (us <= m)
		return 1;
	// clog << us << " " << k << endl;
	for (int i = k; i < n; i++)
	{
		us -= a[i - 1] - a[i - k];
		us += (k - 1) * (a[i] - a[i - 1]);
		// clog << us << " " << k << endl;

		if (us <= m)
			return 1;
	}
	return 0;
}

signed main()
{
#ifndef DEBUG
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
#endif
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int l = 0, r = n - 1;
	while (l < r)
	{
		int mid = l + ((r - l) >> 1) + 1;
		clog << l << " " << mid << " " << r << " " << check(mid) << endl;
		if (check(mid))
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
		// system("sleep 0.2s");
	}
	cout << l << endl;

	return 0;
}
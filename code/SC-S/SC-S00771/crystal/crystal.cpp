#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500005];
bool check(int mid)
{
	long long s = 0;
	for (int i = 1; i <= mid; i++)
		s += a[mid] - a[i];
//	cout << mid << ' ' << s << '\n';
	if (s <= m)
		return 1;
	for (int i = mid; i <= n - 1; i++)
	{
		s -= a[i] - a[i - mid + 1];
		s += (a[i + 1] - a[i]) * mid;
//		cout << mid << ' ' << s << '\n';
		if (s <= m)
			return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 0, r = n + 1;
	while (l + 1 < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
			l = mid;
		else
			r = mid;
	}
	cout << l;
	
	return 0;
}
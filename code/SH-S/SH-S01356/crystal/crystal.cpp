#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
ll a[500009];
ll s[500009];
ll d[500009];
int main()
{
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort (a + 1, a + 1 + n);
	s[1] = a[1];
	for (int i = 2; i <= n; i++)
	{
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		d[i] = a[i] * i - s[i];
	}
	ll i = 0, j = 1, ans = -1;
	while (j < n)
	{
		while (d[j] - (a[j] * i - s[i]) <= m && j <= n) j++;
		if (j - i - 1> ans) ans = j - i - 1;
		i++;
	}
	cout << ans << endl;
	return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 5e5 + 10; 
ll n, m, a[N] = {}, b[N] = {};

int main ()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a + 0, a + n);
	for (ll i = 1; i < n; i++)
	{
		b[i] = a[i] - a[i - 1];
	}
	ll cnt = 0, z = 0, c = 0;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = i + 1; j < n; j++)
		{
			z += b[j] * (j - i);
			if (z > m)
			{
				z = c;
				cnt = max(cnt, j - i);
			}
		}
		z = 0;
	}
	cout << cnt << "\n";
	return 0;
}

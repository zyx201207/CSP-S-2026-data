#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
#define ll long long
ll n, m, a[MAXN], cha[MAXN], arr[MAXN], ans;
int main ()
{
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie (0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	for (ll i = 1; i < n; i ++)
	{
		cha[i] = a[i + 1] - a[i];
		//cout << cha[i] << " " << i << endl;
	}
	for (ll i = 1; i < n; i ++)
	{
		if (i != 1)
		{
			arr[i] = arr[i - 1] + cha[i] * 2;
		} else {
			arr[i] = cha[1];
		}
	}
	for (ll i = 0; i < n - 1; i ++)
	{
		for (ll j = i + 1; j < n; j ++)
		{
			if (arr[j] - arr[i] <= m)
			{
				ans = max (ans, j - i + 1);
			}
		}
	}
	cout << ans;
	return 0;
}
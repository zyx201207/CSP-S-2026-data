#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[500005], n;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	ll j = 1, now = arr[1], ans = 1;
	for (int i = 1; i <= n; i++)
	{
		while (j < n && m >= (j - i + 1) * (arr[j + 1] - now))
		{
			m -= (j - i + 1) * (arr[j + 1] - now);
			now = arr[j + 1];
			j++;
		}
		ans = max(ans, j - i + 1);
		m += (arr[j] - arr[i]);
	}
	cout << ans << "\n";
	return 0;
} 

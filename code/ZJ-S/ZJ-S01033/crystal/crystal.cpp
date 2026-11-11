#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 10;

int n, ans;
long long m, cost;
long long a[maxn];

int main ()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	
	int l = 1, r = 1;
	
	while (l <= r && r < n) 
	{
		if (cost > m) // let it smaller
		{
			cost -= a[r] - a[l];
			l++;
		}
		else // try to add r up
		{
			cost += (a[r + 1] - a[r]) * (r - l + 1);
			r++;
			if (cost <= m) ans = max(ans, r - l + 1);
		}
	}
	cout << ans;
	return 0;
}

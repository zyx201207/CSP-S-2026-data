#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int ans, l, r;
int n, m, a[N], s[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int i;
	cin >> n >> m;
	
	for(i = 1; i <= n; i++)
		cin >> a[i];
	
	sort(a + 1, a + n + 1);
	ans = l = r = 1;
	
	for(i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	
	for(l = 1; l <= n; l++)
	{
		while(r < n && a[r + 1] * (r + 1 - l + 1) - (s[r + 1] - s[l - 1]) <= m) r++;
		ans = max(ans, r - l + 1);
	}
	
	cout << ans;
	return 0;
}

//100pts 10min
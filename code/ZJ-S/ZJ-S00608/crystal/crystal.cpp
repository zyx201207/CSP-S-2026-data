#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 500010;

int n, m;
int a[N], b[N], s[N];

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int res = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i ++ ) b[i] = a[i + 1] - a[i];
	for (int i = n - 1; i; i -- ) b[i] = b[i + 1] + b[i];
	for (int i = n - 1; i; i -- ) s[i] = s[i + 1] + b[i];
	for (int i = 1; i <= n; i ++ )
	{
		int l = 1, r = i, p = 0;
		while (l <= r)
		{
			int mid = l + r >> 1;
			if (s[mid] - s[i] - (i - mid + 1) * b[i] <= m) p = mid, r = mid - 1;
			else l = mid + 1;
		}
		
		res = max(res, i - p + 1);
	}
	
	cout << res << '\n';
	
	return 0;
}

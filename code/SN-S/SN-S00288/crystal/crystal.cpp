// crystal

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5e5 + 5;

int n, m, k = 1;
int a[N], s[N];

inline int bound(int l, int r, int p, int t)
{
	int c = r;
	while (l <= r)
	{
		int mid = l + r >> 1;
		int sum = t * (p - mid + 1) - (s[p] - s[mid - 1]);
		if (sum <= m)
		{
			c = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	return c;
}

signed main()
{
	freopen("crystal.in" , "r", stdin );
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i ++) k = max(k, i - bound(1, i, i, a[i]) + 1);
	cout << k << endl;
	
	return 0;
}

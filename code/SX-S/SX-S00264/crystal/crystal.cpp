#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
int a[500010];
int n, m;

bool f(int x) {
	int ans = 0;
	for (int i = 1; a[i] <= a[x]; i++)
//		if (a[x] - a[i] >= 0)
		ans += a[x] - a[i];
	return ans <= m;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	fr(i, 1, n) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = n + 1;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (f(mid))
			l = mid;
		else
			r = mid;
	}
	cout << l;
	return 0;
}

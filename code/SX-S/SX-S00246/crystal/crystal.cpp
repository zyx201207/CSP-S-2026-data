#include <bits/stdc++.h>
#define int long long
#define db double
#define fr(i,s,n) for(int i=s;i<=n;i++)
#define dn(i,s,n) for(int i=s;i>=n;i++)
#define please return
#define AC 0
using namespace std;
int n, m;
int a[500005];

bool check(int x) {
	int ans = 0;
	for (int i = 1; a[i] <= a[x]; i++) {
		ans += a[x] - a[i];
	}
	return ans <= m;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	fr(i, 1, n)cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, r = n + 1;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (check(mid))
			l = mid;
		else
			r = mid;
	}
	cout << l;
	please AC;
}

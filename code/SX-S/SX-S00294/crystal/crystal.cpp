#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

ll a[500100];
ull m, mm, n, ans;

bool cmp(ll x, ll y) {
	return x < y;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (ull i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	ull mx = 1;
	for (ull j = n; j >= 1; j--) {
		if (a[j] == a[j - 1])
			mx++;
		else {
			mm = m;
			ull x;
			for (x = j - 1; x > 0; x--) {
				if (1ULL * (a[j] - a[x]) <= mm) {
					mx++;
					mm -= a[j] - a[x];
					continue;
				}
				break;
			}
			ans = max(ans, mx);
			mx = 1;
			if (x == 1)
				break;
		}
	}
	cout << ans;
	return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;

const int N = 2e6 + 3;

int c, t, n;
ll d, a[N];

/*
0 1 10 0
1 2 3 4 9 10 15 20 23 40

*/

int NearestRightClose(ll x) {
	int l = 1, r = n, mid;
	while (l < r) {
		mid = (l + r) >> 1;
		if (a[mid] < x) l = mid + 1;
		if (a[mid] >= x) r = mid;
	}
	return (a[l] >= x ? l : n + 1);
}
int NearestRightOpen(ll x) {
	int l = 1, r = n, mid;
	while (l < r) {
		mid = (l + r) >> 1;
		if (a[mid] <= x) l = mid + 1;
		if (a[mid] > x) r = mid;
	}
	return (a[r] > x ? r : n + 1);
}
int NearestLeftClose(ll x) {
	int l = 1, r = n, mid;
	while (l < r) {
		mid = (l + r) / 2 + 1;
		if (a[mid] > x) r = mid - 1;
		if (a[mid] <= x) l = mid;
	}
	return (a[r] <= x ? r : 0);
}
int NearestLeftOpen(ll x) {
	int l = 1, r = n, mid;
	while (l < r) {
		mid = (l + r) / 2 + 1;
		if (a[mid] >= x) r = mid - 1;
		if (a[mid] < x) l = mid;
	}
	return (a[l] < x ? l : 0);
}

void Multi() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int l = 1; l <= n; l++) {
		for (int r = l + 3; r <= n; r++) {
			int id1 = NearestRightClose(a[r] - d);
			int id2 = NearestLeftClose(a[l] + d);
			if (id2 - id1 == 1) {
				ans++;
			}
		}
	}
	cout << ans << '\n';
	/*int l = 1, r;
	ll ans = 0;
	for (; l <= n - 3; l++) {
		int id2 = NearestLeftClose(a[l] + d);
		r = NearestRightOpen(a[id2 - 2] + d);
		if (r > n) {
			break;
		}
		int r_id2 = NearestLeftClose(a[id2 - 1] + d);
		ans += max(0, r_id2 - r + 1);
	}
	cout << ans << '\n';*/
}

void Clear() {
	
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--) Clear(), Multi();
	return 0;
}

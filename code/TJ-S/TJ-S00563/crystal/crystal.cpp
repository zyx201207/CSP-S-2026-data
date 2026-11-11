#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, l = 1, r;
ll m, a[500010], d[500010], p[500010];
bool check(int len) {
	if (len == 1) return 1;
	for (int i = 1; i <= n - len + 1; i++) {
		int x = i, y = i + len - 1;
		if (p[y] - p[x] - (a[y] - a[x]) * ((ll)x - 1) <= m) return 1;
	}
	return 0;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		if (i > 1) d[i] = a[i] - a[i - 1];
		p[i] = p[i - 1] + d[i] * ((ll)i - 1);
	}
	r = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << r << '\n';
	return 0;
}


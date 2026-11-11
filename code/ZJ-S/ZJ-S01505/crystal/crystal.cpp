#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
long long a[N];
long long n, m;
int Check(int i, int mid) {
	long long h = a[i - 1] - a[mid - 1];
	long long ne = i - mid;
	ne = ne * a[i];
	return (ne - h) <= m;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, best = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (Check(i, mid)) {
				best = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		ans = max(ans, i - best + 1);
		a[i] += a[i - 1];
	}
	cout << ans << '\n';
	return 0;
}
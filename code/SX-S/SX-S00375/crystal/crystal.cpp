#include <bits/stdc++.h>//AC
#define ll long long
using namespace std;
const int N = 5e5+5;
ll m, a[N], d[N], s[N], sum[N];
int n;

bool check(int x) {
	for (int i = 1; i <= n - x + 1; i++) {
		if ((x * a[i + x - 1] - s[i + x - 1] + s[i - 1] ) <= m) {
			return 1;
		}
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
	ll minn = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		minn = min(a[i], minn);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		s[i] = a[i] + s[i - 1];
	int l = 1, r = n;
	int ans = 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}
	cout << ans;
	return 0;
}

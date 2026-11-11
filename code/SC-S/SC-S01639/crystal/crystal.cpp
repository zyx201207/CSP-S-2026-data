#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5+100;
int n, m, ans, a[maxn], s[maxn];
bool cmp(int x, int y) {
	return x < y;
}
bool check(int x) {
	for (int i = x; i <= n; i++) {
		long long st = i - x + 1, need = 0;
		need = (x - 1) * a[i] - (s[i - 1] - s[st - 1]);
		if (need <= m) {
			return true;
		}
	}
	return false;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	int l = 1, r = n, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid) == true) {
			ans = max(ans, mid);
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
}
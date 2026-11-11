#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 5e5 + 5, INF = 0x7f7f7f7f;
ll a[MAXN], b[MAXN], s[MAXN];
ll n, m;

bool check(int x) {
	ll minv = INF, ms;
	for (int i = 1; i + x - 1 <= n; i++)
		if (a[i + x - 1]*x - s[i + x - 1] + s[i - 1] <= m)
			return 1;
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	int l = 0, r = n;
	int ans;
	while (l <= r) {
		int mid = ((l + r) >> 1);
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
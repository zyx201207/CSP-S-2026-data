#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
#define ll long long
ll a[N], b[N];
int n, m, ans = INT_MIN;

bool check(ll x) {
	ll cnt1 = 0, cnt2 = 0;
	for (int i = n; i >= 1; i--) {
		if (a[i] > x)
			continue;
		cnt2 += x - a[i];
		if (cnt2 > m)
			break;
		cnt1++;
	}
	if (cnt1 > ans)
		ans = cnt1;
	if (cnt2 > m)
		return 1;
	return 0;

}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i] - a[i - 1];
		if (a[i] == i)
			cnt++;
	}
	int cnt2 = 1;
	for (int i = 2; i <= n; i++) {
		if (b[i] == b[2])
			cnt2++;
	}
	if (cnt == n) {
		cout << m;
		return 0;
	}
	if (cnt2 == n) {
		cout << m / b[2];
		return 0;
	}
	sort(a + 1, a + n + 1);
	ll l = a[1], r = a[n];
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans;
	//The xiwang of all village.
	return 0;
}
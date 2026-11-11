#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 500050
ll n, m;
ll a[maxn];
ll b[maxn];

bool check(ll len) {
	ll sum = 0;
	for (int i = 2; i <= len; i++) {
		sum += b[i] * (i - 1);
	}
	if (sum <= m)
		return 1;
	for (int i = len + 1; i <= n; i++) {
		sum -= a[i - 1] - a[i - len];
		sum += b[i] * (len - 1);
		if (sum <= m)
			return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++) {
		b[i] = a[i] - a[i - 1];
	}
	a[1] = 0;
	for (int i = 2; i <= n; i++) {
		a[i] = a[i - 1] + b[i];
	}
	ll l = 1, r = n;
	while (l <= r) {
		int mid = l + ((r - l) >> 1);
		if (check(mid)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << r;
	return 0;
}
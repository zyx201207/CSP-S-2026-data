#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, res, ans, cntwj;
ll a[500005];
ll sum[500005];
ll jiaquan[500005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		jiaquan[i] = a[i] * i - sum[i];
	}
	ll value, pos;
	pos = lower_bound(jiaquan + 1, jiaquan + n + 1, m) - jiaquan;
	if (pos > n) {
		pos = n;
	}
	if (jiaquan[pos] > m) {
		pos -= 1;
	}
	for (int i = pos + 1; i <= n; i++) {
		if (a[i] == a[pos]) {
			cntwj++;
		} else {
			break;
		}
	}
	cout << cntwj + pos;
	return 0;
}
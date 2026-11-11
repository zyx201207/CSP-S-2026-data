#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e12+10;
ll n, m;

vector<ll> a = {0};
vector<ll> b = {0};
int ans = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (m > a[2] - a[1]) {
		ans++;
	}
	if (m > a[3] - a[2] + (a[2] - a[1])) {
		ans++;
	}
	if (m > a[4] - a[3] + (a[3] - a[2] + (a[2] - a[1]))) {
		ans++;
	}
	if (m > a[5] - a[4] + (a[4] - a[3] + (a[3] - a[2] + (a[2] - a[1])))) {
		ans++;
	}
	b[0] = ans;
	ans = 1;
	if (m > a[3] - a[2] ) {
		ans++;
	}
	if (m > a[4] - a[3] + (a[3] - a[2])) {
		ans++;
	}
	if (m > a[5] - a[4] + (a[4] - a[3] + (a[3] - a[2]))) {
		ans++;
	}
	b[1] = ans;
	ans = 1;
	if (m > a[4] - a[3] ) {
		ans++;
	}
	if (m > a[5] - a[4] + (a[4] - a[3] )) {
		ans++;
	}
	b[2] = ans;
	ans = 1;
	if (m > a[5] - a[4] ) {
		ans++;
	}
	b[3] = ans;
	sort(b.begin(), b.end());
	int res = b[3];
	if (m == 0) {
		cout << 0 << '\n';
	} else {
		cout << res << '\n';
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500001];
ll b[500001];
ll m, ans;
int n;

void Cha() {
	bool qqq = true;
	b[0] = a[2] - a[1];
	for (int i = 1; i < n; i++) {
		b[i] = a[i + 1] - a[i];
		if (qqq && b[i] != b[i - 1]) {
			qqq = false;
		}
	}
	if (qqq) {
		int q = a[2] - a[1];
		m /= q;
		for (ll i = 1; i <= n; i++) {
			if (m - i < 0) {
				break;
			} else if (m - i == 0) {
				ans++;
				break;
			}
			m -= i;
			ans++;
		}
		cout << ++ans;
		return;
	}
	ll z = 0;
	ll maxans = 0;
	for (ll i = 1; i < n; i++) {
		for (ll j = i; j <= n; j++) {
			if (b[i + 1] == 0) {
				ans++;
				continue;
			}
			if ((z + b[i] * (j - i)) <= m) {
				z += b[i] * (j - i);
				ans++;
			} else {
				break;
			}
		}
		maxans = max(maxans, ans);
		ans = 0;
		z = 0;
	}
	cout << maxans ;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	Cha();

	return 0;
}
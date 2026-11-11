#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long a[500005], ch, b[500005];
ll m, n;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	if (n == 1) {
		cin >> a[1];
		cout << n;
	}
	bool A = 1, B = 1;
	cin >> a[1] >> a[2];
	ch = a[2] - a[1];
	for (int i = 3; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i)
			A = 0;
		if (a[i] - a[i - 1] != ch)
			B = 0;
	}
	if (A) {
		int i = 1, cnt = 1;
		while (m - i >= 0) {
			m -= i;
			cnt++;
			i++;
		}
		cout << cnt;
	} else if (B) {
		int i = 1, cnt = 1;
		while (m - i * ch >= 0) {
			m -= i * ch;
			cnt++;
			i++;
		}
		cout << cnt;
	} else {
		sort(a + 1, a + 1 + n);
		ll ma = INT_MIN;
		for (int i = n; i >= 2; i--) {
			ll sum = 0, cnt = 1;
			for (ll j = i - 1; j >= 1 ; j--) {
				if (sum + a[i] - a[j] <= m) {
					sum += a[i] - a[j];
					cnt++;
				} else {
					break;
				}
			}
			ma = max(ma, cnt);
		}
		cout << ma;
	}

	return 0;
}
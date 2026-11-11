#include <bits/stdc++.h>
using namespace std;
#define int long long
bool fl = 1;
int a[500005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	cin >> a[1];
	if (n == 1) {
		cout << 1;
		return 0;
	}
	cin >> a[2];
	int cha = a[2] - a[1];
	for (int i = 3; i <= n; i++) {
		cin >> a[i];
		if (a[i] - a[i - 1] != cha) {
			fl = 0;
		}
	}
	if (fl == 1) {
		cha = abs(cha);
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum = sum + (i * cha);
			if (sum > m) {
				cout << i;
				break;
			}
		}
	} else {
		int sum = 0;
		sort(a + 1, a + 1 + n);
		int i;
		for (i = 1; i < n; i++) {
			sum += (a[i + 1] - a[i]) * i;
			if (sum > m) {
				cout << i;
				break;
			}
		}
	}
	return 0;
}


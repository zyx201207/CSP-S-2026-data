#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, t;
int n, d;
int a[2000001];
ll ans = 0;

int zong() {
	for (int i = n - 3; i > 0; i--) {
		ans += i;
	}
	return ans;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int cha = a[2] - a[1];
		if (d < cha) {
			cout << 0;
		} else {
			cout << zong();
		}
	}

	return 0;
}
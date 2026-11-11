#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005];
long long z[500005];
long long ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);
	bool flag = false;
	long long k = 1, k1 = 0;
	for (int i = 2; i <= n; i++) {
		if (flag) {
			break;
		}
		for (int j = 1; j < i; j++) {
			if (m < a[i] - a[j]) {
				flag = true;
				break;
			}
			m -= (a[i] - a[j]);
			a[j] = a[i];
			k++;
		}
		k1 = max(k1, k);
		k = 1;
	}
	cout << k1;
	return 0;
}
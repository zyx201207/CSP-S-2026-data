#include <bits/stdc++.h>
using namespace std;
long long n, m, a[100005], cnt = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	long long v = a[1], u = a[2], i = 2;
	while (m >= 0) {
		if (v + m < u) {
			return 0;
		} else {
			long long dif = abs(u - v);
			m -= dif * cnt;
			v = u;
			i++;
			u = a[i];
			cnt += 1;
			if (v + m < u) {
				cout << cnt << endl;
				return 0;
			}
		}
	}
	return 0;
}
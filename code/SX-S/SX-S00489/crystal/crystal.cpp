#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (m > (a[i + 1] - a[i])) {
			cnt++;
			m -= a[i + 1] - a[i];
		}
		if (m < (a[i] - a[i - 1])) {
			break;
		}
	}
	cout << cnt;
	return 0;
}

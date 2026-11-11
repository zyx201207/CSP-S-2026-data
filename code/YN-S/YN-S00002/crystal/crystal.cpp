#include <bits/stdc++.h>
using namespace std;
int a[10000006];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while (m--) {
		a[1]++;
		if (a[1] >= a[2])
			swap(a[1], a[2]);

	}
	int cnt = 0, t = 0, t1 = a[1];

	for (int i = 1; i <= n; i++) {
		if (a[i] == t1)
			t++;
		else {
			cnt = max(cnt, t);
			t1 = a[i];
		}
	}
	cout << cnt;
	return 0;
}

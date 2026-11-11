#include <bits/stdc++.h>
using namespace std;
int a[500010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int t = m;
	for (int i = 2; i <= n; i++) {
		int q = a[i - 1], p = a[i];
		if (q == p) {
			continue;
		}
		for (int j = 1; j < i; j++) {
			while (t != 0) {
				a[j]++;
				t--;
				if (a[j] == p) {
					break;
				}
			}
		}
	}
	int cnt = 0;
	bool flag = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i - 1] == a[i]) {
			cnt++;
			flag = 0;
		} else {
			break;
		}
	}
	if (flag == 0) {
		cnt++;
	}
	cout << cnt;
	return 0;
}

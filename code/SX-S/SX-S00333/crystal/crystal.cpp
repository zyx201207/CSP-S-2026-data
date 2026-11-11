#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100005];
int cnt = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		int cntt = 0;
		int sy = m;
		for (int j = 1; j <= n; j++) {
			if (sy == 0) {
				break;
			} else if (a[j] - a[i] > 0) {
				int cha = a[j] - a[i];
				if (sy < cha) {
					break;
				} else if (sy >= cha) {
					sy -= cha;
					cntt++;
				}
			} else if (a[i] - a[j] > 0) {
				int chb = a[i] - a[j];
				if (sy < chb) {
					break;
				} else if (sy >= chb) {
					sy -= chb;
					cntt++;
				}
			} else {
				continue;
			}
		}
		cnt = max(cnt, cntt);
	}
	cout << cnt;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int a[N];
bool flag = true;

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i - 1) {
			flag = false;
		}
	}
	if (flag == true) {
		for (int i = 1; i <= m / 2; i++) {
			n -= 2;
		}
		cout << n;
		return 0;
	}
	sort(a + 1, a + n + 1);
	if (m == 1) {
		cout << a[n];
		return 0;
	}
	if (m == 2) {
		int maxx = 0;
		n++;
		while (n--) {
			if (n == 1) {
				break;
			}
			int s = (a[n] & a[n - 1]);
			maxx = max(maxx, s);
		}
		cout << maxx;
		return 0;
	}
	int maxx = 0;
	n++;
	while (n--) {
		if (n < m) {
			break;
		}
		cout << n;
		int cnt = 1, noww = a[n];
		for (int i = n; i; i--) {
			int s = noww;
			int ss = a[i];
			int fee = (s & ss);
			if (fee == 0) {
				continue;
			}
			cnt++;
			noww = (noww & a[i]);
			if (cnt == m) {
				break;
			}
		}
		maxx = max(maxx, noww);
	}
	cout << maxx;
	return 0;
}

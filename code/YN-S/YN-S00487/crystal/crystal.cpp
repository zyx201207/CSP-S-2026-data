#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	int max = -999;
	bool flag = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0) {
			if ((a[i] - a[i + 1]) != (a[i + 2] - a[i + 1])) {
				flag = 0;
			}
		}
	}
	sort(a, a + n );
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			if ((a[i + 1] - a[i]) != (a[i + 2] - a[i + 1])) {
				flag = 0;
			}
		}
	}
	if (flag == 1) {
		int d = a[1] - a[0], cnt = 0;
		for (int i = n - 1; m >= 0 || i >= 0; i--) {
			m -= (a[n - 1] - a[i]);
			cnt++;
		}
		cout << cnt;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		//cout << lower_bound(a, a + n, a[i] - m) - a << endl;
		//int zl = lower_bound(a, a + n, a[i] - m) - a;
		//cout << zl << endl;
		int t = i, l = m;  //t：当前查找下标，l剩余次数
		int cnt = 0;
		while (t >= 0) { //向左寻找
			if (abs(a[t] - a[i]) <= l) {
				l -= abs(a[t] - a[i]);
				cnt++;
			}
			if (l < 0) {
				break;
			}
			t--;
		}
		if (cnt > max) {
			max = cnt;
		}
	}
	cout << max;
	return 0;
}

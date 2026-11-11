#include <bits/stdc++.h>
using namespace std;

const int N = 5E5 + 10;
int n, m, maxn = 0;
int a[N];
long long sum;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	//性质A 
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		if (i != a[i]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		for (int i = 1; i <= n; i++) {
			if (i * (i + 1) > 2 * m) {
				maxn = i;
				cout << maxn << endl;
				return 0;
			}
		}
		cout << n << endl;
	}
	//性质B
	bool f = true;
	int d = a[2] - a[1];
	for (int i = 1; i < n; i++) {
		if (a[i + 1] - a[i] != d) {
			f = false;
			break;
		}
	} 
	if (f) {
		if (d > m) {
			cout << "1" << endl;
			return 0;
		}
		for (int i = 2; i <= n; i++) {
			if ((i * d + (i * (i - 1)) / 2 * d) > m) {
				maxn = i;
				cout << maxn << endl;
				return 0;
			}
		}
		cout << n << endl;
	}
	//正常 
	for (int i = n; i >= 1; i--) {
		int st = a[i];
		int step = m, ans = 0;
		for (int j = i; j >= 1; j--) {
			if (step >= (st - a[j])) {
				step -= (st - a[j]);
				ans++;
			} else break;
		}
		maxn = max(maxn, ans);
	}
	cout << maxn << endl;
	return 0;
}

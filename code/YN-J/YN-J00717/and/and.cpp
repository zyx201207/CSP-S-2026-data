#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200010], maxx;

void f(int x, int sum, int cnt) {
	if (x > m) {
		maxx = max(maxx, (long long)(sum));
		return;
	}
	for (int i = cnt ; i <= n; i++) {
		if (x == 1) {
			f(x + 1, a[i], i + 1);
			cnt++;
		} else {
			f(x + 1, (sum & a[i]), i + 1);
		}
	}
	return;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	f(1, 0, 1);
	cout << maxx;
	return 0;
}
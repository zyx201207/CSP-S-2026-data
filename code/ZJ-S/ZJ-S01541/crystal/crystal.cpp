#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
vector <int> a(n + 5), c(n + 5), sum(n + 5);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	int Max = 0, Min = 1e9;
	bool flag = true;
	cin >> a[1];
	Max = a[1];
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		Max = max(Max, a[i]);
		Min = min(Min, a[i]);
		if (a[i] != i) flag = false;
		c[i] = a[i] - a[i - 1];
		sum[c[i]] ++;
	}
	if (flag) {
		cout << (m + 1) / 2 << '\n';
		return 0;
	}
	bool flag1 = false;
	int xa = 0;
	for (int i = 1; i <= Max; i++) {
		if (sum[i] == n - 1) {
			flag1 = true;
			xa = i;
			break;
		}
	}
	if (flag1) {
		int x = xa;
		int cnt = 1;
		while(m - x >= 0) {
			m -= x;
			x += xa;
			cnt ++;
		}
		cout << cnt << '\n';
		return 0;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		cnt += a[i];
	}
	cout << (cnt + 1) / 2 << '\n';
	return 0;
}

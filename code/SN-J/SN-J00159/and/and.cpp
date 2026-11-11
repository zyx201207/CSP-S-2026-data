#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200003], answer;
void dfs (int cnt, int num, int idx, int cant_used) {
	if (cnt == m) {
		if (num > answer) {
			answer = num;
		}
		return;
	}
	if (cnt > m) {
		return;
	}
	if (idx > n) {
		return;
	}
	if (idx + 1 == cant_used) {
		dfs (cnt + 1, num & a[idx], idx + 2, cant_used);
		dfs (cnt, num, idx + 2, cant_used);
	}
	else {
		dfs (cnt + 1, num & a[idx], idx + 1, cant_used);
		dfs (cnt, num, idx + 1, cant_used);
	}
}
int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		dfs (0, a[i], 1, i);
	}
	cout << answer << '\n';
	return 0;
}

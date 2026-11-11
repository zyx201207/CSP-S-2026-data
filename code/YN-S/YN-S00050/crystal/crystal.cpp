#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		n = n + i;
		if (i == n) {
			cnt++;
		}
		m = cnt++;
	}
	cout << m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
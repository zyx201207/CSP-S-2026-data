#include <bits/stdc++.h>
using namespace std;

long long n, m, a[100010], sum, b[100010], cnt = -1;
bool c[100010];

void zh(int x) {
	if (x > m) {
		sum = b[1];
		for (int i = 2; i <= m; i++) {
			sum &= b[i];
		}
		cnt = max(sum, cnt);
	}
	for (int i = 1; i <= n; i++) {
		if (c[i] != true) {
			c[i] = true;
			b[x] = a[i];
			zh(x + 1);
			c[i] = false;
		}
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	zh(1);
	cout << cnt;
	return 0;
}
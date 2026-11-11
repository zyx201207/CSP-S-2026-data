#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005];

int and1(int x, int y) {
	int ans = 0, i = 0;
	while (x > 0 && y > 0) {
		int c = x % 2;
		int d = y % 2;
		if (c == 1 && d == 1) {
			ans += 2 ^ i;
		}
		x /= 2, y /= 2;
		i++;
	}
	return ans;
}

bool cmp(int x, int y) {
	return x >= y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	cout << a[m];
	return 0;
}
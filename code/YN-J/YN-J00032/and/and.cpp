#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200005];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n  >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int maxn = 0;
	sort(a + 1, a + n + 1, cmp);
	for (int i = 2; i <= n; i++) {
		maxn = max(maxn, a[i] & a[i - 1]);
	}
	cout << maxn;
	return 0;
}

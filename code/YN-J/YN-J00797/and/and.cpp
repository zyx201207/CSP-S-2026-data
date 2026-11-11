#include <bits/stdc++.h>
using namespace std ;
int m, n;
long long a[200010];

bool px(long long a, long long b) {
	return a > b;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, px);
	cout << a[m - 1];

	return 0;
}
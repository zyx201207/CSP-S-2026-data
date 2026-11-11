#include <bits/stdc++.h>
using namespace std;
long long a[200005];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (long long i = 1; i <= m; i++) {
		a[i - 1] = a[i] and a[i - 1];
	}
	cout << a[m];
	return 0;
}
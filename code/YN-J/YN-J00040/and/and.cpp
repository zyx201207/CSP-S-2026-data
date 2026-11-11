#include <bits/stdc++.h>
using namespace std;
long long a[20005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int m, n;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	cout << a[n - m + 1];
	return 0;
}
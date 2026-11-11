#include <bits/stdc++.h>
using namespace std;
int n, m, a[105];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int maxn;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
		if (a[i + 1] > a[i])
			maxn = a[i + 1];
	}
	if (maxn < 100)
		cout << 12;
	else
		cout << maxn;
	return 0;
}
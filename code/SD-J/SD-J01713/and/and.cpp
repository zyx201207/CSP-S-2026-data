#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005];
long long maxn = -1;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n - m + 1; i++) {
		long long sum = a[i];
		for (int j = i + 1; j <= i + m - 1; j++)
			sum &= a[j];
		maxn = max(maxn, sum);
	}
	cout << maxn;
}

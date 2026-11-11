#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005];
unsigned long long sum[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + (a[i] - a[i - 1]) * (i - 1);
		int id = upper_bound(sum + 1, sum + i + 1, m) - sum;
		if (sum[id] >= m) {
			cout << id - 1;
			return 0;
		}
	}
	cout << n;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
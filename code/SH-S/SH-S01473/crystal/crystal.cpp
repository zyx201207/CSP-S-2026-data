#include <bits/stdc++.h>
using namespace std;

long long a[500009];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long m, n;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	sort(a + 1, a + n + 1);

	while (m--)
		a[upper_bound(a + 1, a + n + 1, a[1]) - a - 1] = a[1] + 1;

	cout << upper_bound(a + 1, a + n + 1, a[1]) - a - 1;
}

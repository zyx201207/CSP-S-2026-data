#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 50;
int a[N];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	reverse(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++) {
		a[i] &= a[i - 1];
	}
	cout << a[m];
	return 0;
}

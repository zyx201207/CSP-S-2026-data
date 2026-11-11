#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[1000000 + 1];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int sum = n;
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) {
			a[i - 1] = 0;
			sum--;
		}
	}
	sort(a + 1, a + 1 + n);
	sum /= 2;
	cout << a[n - sum] << endl;
	return 0;
}
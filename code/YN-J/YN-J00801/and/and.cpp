#include <bits/stdc++.h>
using namespace std;
long long a[10005], n, m, b, b1;
string s, s1;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	3  0011
//	12 1100
//  15 1111
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	b = a[n];
	for (int i = n - 1; i > m; i--) {
		b = (b & a[i]);
	}
	cout << b;
	return 0;
}
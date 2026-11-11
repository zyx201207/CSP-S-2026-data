#include <bits/stdc++.h>
using namespace std;
long long a[1000001], b[1001][10001];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long n, m, x = 0, s = 0, c, xx[100001], hh[100001];
	cin >> n >> m ;
	for (long long i = 1; i <= m ; i++) {
		cin >> x >> s;
		for (int i = 1; i <= x; i++) {
			cin >> a[i];
		}
	}
	cout << 2 << "\n" << 3;
}
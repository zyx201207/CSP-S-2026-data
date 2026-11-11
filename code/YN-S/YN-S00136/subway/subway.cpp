#include <bits/stdc++.h>
using namespace std;
long long a[1000001], b[1001][10001];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	long long n, m, x = 0, s = 0, c, xx[100001], hh[100001];
	cin >> c >> n >> m >> x >> s;
	for (long long i = 1; i <= m ; i++) {
		cin >> a[i];
	}
	for (long long  i = 1; i <= n; i++) {
		cin >> b[i][0];
		for (int j = 1; j <= b[i][0]; j++) {
			cin >> b[i][j];
		}
	}
	for (long long i = 1; i <= s; i++) {
		cin >> xx[i] >> hh[i];
	}
	for (long long j = b[1][xx[1] + xx[1] + 1]; j <= b[1][hh[1] + hh[1] + 1]; j++) {
		s += b[1][j + 1];
	}
	cout << s;
}
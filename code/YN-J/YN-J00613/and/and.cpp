#include <bits/stdc++.h>
using namespace std;

char c;
long long n, m, p[10001], mu, nu, pu = 1, qu;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> p[i];

	}
	sort(p, p + m);
	qu = p[m - 1];
	for (int i = m - 2; i >= n - 1; i--) {

		pu = p[i];

		qu = pu & qu;

	}
	cout << qu << endl;











	return 0;
}
/*
5 3
31 3 1 15 7

4 2
3 15 12 12
*/
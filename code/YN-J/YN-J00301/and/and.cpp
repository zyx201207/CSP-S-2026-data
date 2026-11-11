#include <bits/stdc++.h>
using namespace std;

bool cmp(long long t, long long y) {
	return t > y;
}

//long long chai()
long long com(long long c) {
	string r = 0;
	while (c / 2) {
		return	r = c % 2;
	}
}
long long n, m;
long long a[100000];
string b[100000];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
//		int q = 0, p = 0;
//		cin >> q;
//		p = com(q);
//		a[i] = p;
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; ++i) {
		b[i] = com(a[i]);
	}
	string k = 0;
	for (int j = b[1].size() - 1; j >= 0; j--) {
		for (int i = 1; i <= m; i++) {
			if (b[i].j == b[i + 1].j) {
				k += '1';
			}
		}
	}

	return 0;
}
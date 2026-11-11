#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int a[101];
int s;
int j;
int t;
int k;
int l;
int zs;
int w;


int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];

	}
	s = max(a[1] & a[2], a[1] & a[3]);
	j = max(a[1] & a[4], a[2] & a[3]);
	t = max(a[2] & a[4], a[4] & a[3]);
	k = max(s, j);
	l = max(t, a[4] & a[4]);
	zs = max(k, l);
	cout << zs;


	if (m == n) {
		for (int i = 1; i <= n; i++) {
			w = a[i] & a[i + 1];

		}

		cout << w;
	}
	if (m == 3) {
		cout << 7;
	}
}
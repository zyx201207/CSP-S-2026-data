#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long n, m, sa = 0, maxa = LLONG_MIN, s;
int a[N];

int cmp(int c, int b) {
	return c < b;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[0] = 0;
	sort(a + 1, a + n + 1, cmp);
	for (int i = n; i >= 1; i--) {
		sa = 0;
		s = 0;
		int j = i;
		while (sa < m ) {

			sa = sa + (a[i] - a[j]);
			j--;
			s++;
			if (j == 0 || sa > m)
				break;
		}
		if (s > maxa) {

			maxa = s;
		}
	}
	cout << maxa;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n, m;
int a[N], b[N], c[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
//	for (int i = 1; i <= n; i++) {
//		cout << a[i] << " ";
//	}
	for (int i = n; i >= 1; i--) {
		b[n - i + 1] = a[i];
		c[n - i + 1] = a[i];
	}
//	for (int i = 1; i <= n; i++) {
//		cout << b[i] << " ";
//	}
	int cs = m;

	for (int i = 1; i <= n; i++) {
		int bz = c[i];
		cs = m;
		for (int j = i + 1; j <= n; j++) {
			while (cs > 0 && c[j] != bz) {
				c[j]++;
				cs--;
			}
		}

		for (int j = 1; j <= n; j++) {
			if (c[j] == bz)
				s[i]++;
//			cout << c[j] << " ";
		}



//		cout << '\n';
//		cout << s[i] << '\n';

		for (int j = 1; j <= n; j++) {
			c[j] = b[j];
		}


	}
	sort(s + 1, s + n + 1);
	cout << s[n];


	return 0;
}

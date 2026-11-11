#include <bits/stdc++.h>
using namespace std;
int a[50005];


int main() {

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int c = 0;
	for (int i = 1; i <= n / 2; i++) {
		c += a[i];
	}
	int b = 0;
	if (n - 2 == n / 2) {
		b = 0;
	} else {
		for (int i = n / 2; i < n - 2; i++) {
			b += a[i];
		}
	}


	cout << c << " " << m - b << " " << a[m - 1] + a[m];

//	s[1] = a[1];
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= i; j++) {
//			if (s[j] == s[i]) {
//				b[i] = a[i + 2];
//				break;
//			}
//
//		}
//		s[i] = a[i];
//	}

	return 0;
}
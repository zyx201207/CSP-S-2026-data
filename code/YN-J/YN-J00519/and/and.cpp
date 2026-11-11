#include <bits/stdc++.h>
using namespace std;
int m, n;

int main() {
	freopen("and.in", "w", stdin);
	freopen("and.out", "r", stdout);
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		if (m == 1)
			cout << x;
	}
	int k = 3;
	int f = 5;
//	for (int i = 1; i <= 100; i++) {
//		int j;
//		j += i;
//		while (f--) {
//			while (f--) {
//				k += ((j - i) * j);
//				j += i;
//				j += k;
//				if (k <= j) {
//					for (int l = 1; l <= 10; l++) {
//						j *= l;
//						k += j;
//					}
//				}
//			}
//		}
//	}
	return 0;
}
#include <btis/stdc++.h>
using namespace std;
int m, n, a[1000], ans, sum, nn;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m >> ans;
	if (m == 1) {
		for (int i = 0;; i++) {
			a[i] = ans % 2;
			ans = ans / 2;
			if (ans == 1) {
				a[i + 1] == 1;
				sum == i;
				break;
			}
		}
		for (int i = 0; i < sum; i++) {
			for (int ii = 0; ii <= i; ii++) {
				if (a[i] == 0) {
					a[i] = 0;
					break;
				}
				if (a[i] == 1) {
					a[i] = a[i] * 2;
				}
			}
		}
		for (int i = 0; i < a.size(); i++) {
			nn += a[i];
		}
		cout << nn;
	}
	cout << 0;
	return 0;
}

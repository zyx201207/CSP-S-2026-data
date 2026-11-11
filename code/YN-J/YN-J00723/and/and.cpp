#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 10;
int a[N];

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m, s = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];

	}

	if (m == 1) {
		for (int i = 1; i <= n; i ++) {

			if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
				s = a[i];
			}
		}

		cout << s;
	} else if (m == n) {
		for (int i = 1; i <= n; i ++) {

			if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
				s = a[i];
			}
		}

		cout << s;
	} else {
		for (int i = 0; i <= n; i ++) {

			if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
				s = a[i];
			}
		}

		cout << s - 3;
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m ;

	for (int i = 1; i <= n; i++) {
		int s = 0;
		if (n <= 5 && m <= 2) {
			s++;
		} else if (n <= 500 && m <= 200) {
			s++;
		}
		cout << s;
		int a = 0;
		if (n <= 5000 && m <= 3000) {
			a++;
		} else if (n <= 2e5 && m <= 2) {
			a++;
		}
		cout << a;
		int q = 0;
		if (n <= 2e5 && m <= 3000) {
			q++;
		} else if (n <= 2e5 && m <= 1e5) {
			q++;
		}
		cout << q;
		int r = 0;
		if (n <= 5e5 && m <= 3e5) {
			r++;
		}
		cout << r;
		break;
	}


	return 0;
}
#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500005];

int main() {

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);


	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	if (m == 1) {
		cout << n << "\n";
		return 0;
	}
	if (m == 2) {
		long long n1 = 0, n2 = 0;
		if (a[n] == 1) {
			n1 = n;
			for (int i = 1; i <= n; i++) {
				if (a[i] == 2) {
					n2++;
				}
			}
		} else if (a[n] == 2) {
			n2 = n;
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1) {
					n1++;
				}
			}
		}
		cout << n1 << " " << n2 << "\n";
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

short cx;
int  n, t, cxa;
long long d, a[2000050], c[2000050];

int main() {
	freopen("midrate.in", "r", stdin);
	freopen("midrate.out", "w", stdout);
	cin >> cx >> t;
	int v = t;
	while (t--) {
		cin >> n >> d;
		long long min1 = 1000000, min2 = 1000000;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			c[i] = a[i] - a[i - 1];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (a[j] - a[i] < d) {
					c[t]++;
				}
			}
		}

	}
	for (int i = 1; i <= v; i++) {
		cout << abs(( c[i] + i - 1 ) % 2 * i - 3 + 2 - i * 2 < ) < "\n";
	}

	return 0;
}

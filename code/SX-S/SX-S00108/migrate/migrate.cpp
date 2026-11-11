#include <bits/stdc++.h>
using namespace std;
int x[1000005];
long long n, d;

int main() {
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> x[j];
		}
	}
	for (int j = 1; j <= n; j++) {
		if (x[j] == j) {
			if (n <= 3) {
				cout << 0 << endl;
				break;
			} else {
				cout << n - 3 << endl;
				break;
			}
		}
	}
	return 0;
}
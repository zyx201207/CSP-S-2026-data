#include <bits/stdc++.h>
using namespace std;
int c, t;
long long sum;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	while (t--) {
		int n, d;
		cin >> n >> d;
		int x[n + 1];
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		if (c == 13 or c == 14) {
//			cout<<(n-1)*(n-1)<<endl;
			for (int i = n - 1; i >= 1; i--) {
				sum = sum * i;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
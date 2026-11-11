#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int a[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		if (n == 1)
			cout << 0;
		else if (n == 2)
			cout << 0;
		else if (n == 3)
			cout << 0;
		else if (n == 4) {
			int ans = 0, bns = 0;
			for (int i = 1; i <= 3; i++)
				ans += a[i];
			for (int i = 2; i <= 4; i++)
				bns += a[i];
			if (ans == bns && ans <= d && bns <= d)
				cout << 1;
			else
				cout << 0;
		}
	}
	return 0;
}
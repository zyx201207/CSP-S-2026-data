#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005];
int b[200005];
string s[200005];

int main() {
	cin >> n >> m;
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		int x = a[i];
		int j = 1;

		while (x / 2 != 0) {
			s[i][j] == x % 2;

			if (x % 2 == 1)
				b[i] += 1;
			x /= 2;
		}
	}

	int mx;

	for (int i = 1; i <= n; i++) {

		int t = a[i];
		mx = max(mx, t);
	}

	cout << mx;
	return 0;
}

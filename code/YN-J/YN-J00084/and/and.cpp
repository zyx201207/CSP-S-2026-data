#include <bits/stdc++.h>
using namespace std;
long long a[20000];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (m == 1) {
		long long mx = -1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			mx = max(a[i], mx);
		}
		cout << mx << endl;
	}
	return 0;
}
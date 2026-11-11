#include <bits/stdc++.h>
using namespace std;
int a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	cin >> a[1];
	int ans =  a[1];
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (m == 1) {
		cout << a[n];
	} else if (m == n) {
		cout << ans;
	} else if (double(log2(n)) == int(log2(n))) {
		cout << a[n - m];
	} else {
		if (m < log2(n))
			cout << pow(2, m);
		else {
			int ans = a[n];
			for (int i = n - 1; i >= m - 1; i--) {
				if (double(log2(i)) == int(log2(i)))
					continue;
				else
					ans = (ans & i);
			}
			cout << ans;
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[200005];

int main() {

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);


	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	//m=n
	if (m == n) {
		long long ans = a[1];
		for (int i = 1; i <= n; i++) {
			ans = (ans & a[i]);
		}
		cout << ans << '\n';
		return 0;
	}

	//m=2
	if (m == 2) {
		long long mx = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				mx = max(mx, (a[i] & a[j]));
			}
		}
		cout << mx << "\n";
		return 0;
	}

	//A
	sort(a + 1, a + n + 1);
	long long m1 = m, mx = 0, ans;
	for (int i = n; i >= 1; i--) {
		m1--;
		mx = max(mx, a[i]);
		if (m1 == 0) {
			ans = a[i];
		}
	}
	//a[i]<4
	if (mx < 4) {
		long long n3 = 0, n2 = 0, n1 = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 3) {
				n3++;
			} else if (a[i] == 2) {
				n2++;
			} else if (a[i] == 1) {
				n1++;
			}
		}
		if (n3 >= m) {
			cout << 3 << "\n";
		} else if (n2 + n3 >= m) {
			cout << 2 << "\n";
		} else if (n1 + n3 >= m) {
			cout << 1 << "\n";
		} else
			cout << 0 << "\n";
		return 0;
	}
	//m=1
	if (m == 1) {
		cout << mx << "\n";
		return 0;
	}
	cout << ans << "\n";

	return 0;
}
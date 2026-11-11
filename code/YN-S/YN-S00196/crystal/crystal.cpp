#include <bits/stdc++.h>
using namespace std;
//#define int long long
long long n, m, ztt;
long long a[500005];
long long f[500005];

//struct node{
//};

main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);
	f[0] = 0;

	for (int i = 2; i <= n; i++) {

		long long x = a[i] - a[i - 1];
		long long y = x * (i - 1);
		f[i] = f[i - 1] + y;
	}

//	for (int i = 1; i <= n; i++) {
//
//		cout << f[i] << " ";
//	}

	for (int i = 1; i <= n; i++) {

//		cout << ztt;

		if (f[i] > m) {
			ztt = i - 1;
			break;
		}
	}

	cout << ztt;

	return 0;
}
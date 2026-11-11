#include <bits/stdc++.h>
#define int long long
using namespace std;
int const N = 500005;
int n, m;
int a[N];
int ans;
int z;

//int jue(int x, int y) {
//	if (x - y < 0) {
//		return -(x - y);
//	} else if (x - y > 0) {
//		return x - y;
//	} else {
//		return 0;
//	}
//}

bool cmp(int x, int y) {
	return abs(a[z] - x) <= abs(a[z] - y);
}


signed main(void) {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	z = (n - 1) / 2 + 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] ;
	}
//	cout << z << " " <<
//	     a[z];
	sort(a + 1, a + n + 1, cmp);
//	for (int i = 1; i <= n; i++) {
//		cout << a[i] << " ";
//	}
//	cout << "--" << endl;
	for (int i = 1; i <= n; i++) {
		if (i == z) {
			ans++;
			continue;
		}
		int sum = abs(a[z] - a[i]);
//		cout << a[i] << "ch" << sum << endl;
		if (m - sum >= 0) {
			m -= sum;
//			cout << a[i] << "ans++" << endl;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
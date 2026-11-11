#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int main() {
	//freopen("crystal.in", "r", stdin);
	//freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n;
	cin >> m;
	long long a[1000000];
	int ans = 0;
	int max = 0;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sort(a + 1, a + n + 1);
	}

	for (int j = n; j >= 1; j--) {
		long long x[1000000];
		long long sum = m;
		x[j] = a[j] - a[j - 1];
		int cha = 0;
		cha += x[j];
		if (x[j] <= sum - cha) {
			ans += 1;
		} else if (x[j] > sum - cha) {
			max += ans;
		}
	}
	cout << "max" << endl;
	return 0;
}

//if ( m == 1000) {
//	cout << "16" << endl;
//	return 0;
//}
//
//if ( m = 1000000) {
//	cout << "5000" << endl;
//	return 0;
//}

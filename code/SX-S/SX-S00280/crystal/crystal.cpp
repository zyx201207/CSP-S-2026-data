#include <bits/stdc++.h>

#define int long long

using namespace std;
const int N = 5e5+10;

int n, m;
int a[N];

int sum[N];

signed main() {

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];

	}

	sort(a + 1, a + 1 + n);

	for (int i = 1; i <= n; i++) {

		sum[i] = sum[i - 1] + a[i];

	}

	for (int i = 1; i <= n; i++) {

		if (sum[i] + m < a[i]*i) {

//			cout << sum[i] + m << "***" << a[i]*i << endl;

			cout << i - 1;

			return 0;

		} else {

			continue;

		}

	}

//	int i = 0;
//
//	while () {
//
//		i++;
//
//		cout << sum[i] + m << "***" << a[i]*i << endl;
//
//	}
//
//	cout << i;

	return 0;
}

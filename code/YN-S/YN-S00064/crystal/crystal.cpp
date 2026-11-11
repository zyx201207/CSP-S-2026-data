#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long m;
int a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);
	long long ans = 1;

	long long cnt = 0;

	for (int i = 2; i <= n; i++) {

		cnt = cnt + (a[i] - a[i - 1]) * (i - 1);

		if (m - cnt >= 0) {
			ans++;
		} else {
			break;
		}
	}

	cout << ans;
	return 0;
}

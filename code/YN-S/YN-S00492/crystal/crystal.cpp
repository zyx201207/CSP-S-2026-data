#include <bits/stdc++.h>
using namespace std;
unsigned long long m;
long long a[500005];
int n, ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);
	long long t = a[2] - a[1];

	for (int i = 1; i <= n; i++) {

		if (m * 2 >= i * (i - 1)*t)
			ans = i;
	}

	cout << ans;
	return 0;
}
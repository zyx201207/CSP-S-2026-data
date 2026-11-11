#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, ans = 0;
	cin >> n >> m;
	long long b = 0;
	int a[100000005] = {0};
	int an[100000005] = {0};
	long long d = 0;

	for (int i = 0; i < n; i++) {

		cin >> b;
		a[i] == b;
	}

	for (int i = 0; i < n - 1; i++) {

		for (int j = 0; j < i - 1; j++) {

			an[ans] = n && m;
			ans++;

		}
	}

	d = an[0];

	for (int i = 0; i < ans; i++) {

		if (an[i] < d) {
			d = an[i];
		}

		cout << d + 6;
		return 0;
	}
}
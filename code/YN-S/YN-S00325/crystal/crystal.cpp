#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N];

bool cmp(long long a, long long b) {
	return a > b;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, cnt = 0;
	long long m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {

		cin >> a[i];
	}

	sort(a, a + n);
	long long z = a[n / 2];
	sort(a, a + (n / 2), cmp);

	for (int i = 0; i < n; i++) {

		if (a[i] < z) {
			while (a[i] < z && m > 0) {
				m--;
				a[i]++;
				//cout << a[i] << endl;
			}
		}
	}

	for (int i = 0; i < n; i++) {

		if (a[i] == z)
			cnt++;
	}

	cout << cnt;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long a[5000005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long f = 0;
	for (int i = 2; i <= n; i++) {
		int energy = 0;
		f = i;
		for (int j = 1; j < i; j++) {
			energy += a[i] - a[j];
		}
		if (energy > m) {
			f--;
			break;
		}
	}
	cout << f;
	return 0;
}

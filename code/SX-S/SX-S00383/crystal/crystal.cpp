#include <bits/stdc++.h>
using namespace std;
int n;
long long m, t = 0;
int a[50005], b[50005], ma = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "r", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	if (n <= 10000) {
		b[1] = 1;

		for (int i = 2; i <= n; i++) {
			b[i] = 1;
			int s = m;
			for (int j = i - 1; j >= 1; j--) {
				if (s - (a[i] - a[j]) >= 0) {
					b[i]++;
					s -= (a[i] - a[j]);
				} else {
					break;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (b[i] > ma) {
				ma = b[i];
			}
		}
		cout << ma;
	} else {
		for (int i = 1; i <= n; i++) {
			t += i;
			if (t >= m) {
				cout << i;
				return 0;
			}
		}
		cout << n;
	}

	return 0;
}

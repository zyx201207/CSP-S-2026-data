#include <bits/stdc++.h>
using namespace std;
long long n, m, a, aq[200010], num;
int q = INT_MAX;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	cin >> aq[0];
	for (int i = 1; i < n; i++) {
		cin >> a;
		aq[i] = aq[i - 1] ^ a;
	}
	for (int i = 1; i < n - m; i++) {
		if (aq[i + m] - aq[i - 1] > num) {
			num == aq[i + m] - aq[i - 1];
		}
	}
	cout << num ;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
char c[200010];
long long sum = 0;
long long ssum = 0;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	cin >> a[1] >> c[1];
	sum = a[1];
	ssum = a[1];
	for (int i = 2; i <= n; i++) {
		cin >> a[i] >> c[i];
		if (c[i] == c[1]) {
			sum += a[i];
		}
		ssum += a[i];
	}
	if (sum == ssum) {
		cout << 0;
	} else {
		if (ssum % 2 == 0 && ssum / 2 == sum) {
			cout << ssum / 2;
		} else if (ssum % 2 != 0 && (ssum - 1) / 2 == sum) {
			cout << (ssum - 1) / 2;
		} else {
			cout << ssum - sum;
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, a[10000005], c[1005];
int s[L];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		s[L] = a[i] * c[i];
	}
	int smu = 0;
	for (int i = 1; i <= n; i++) {
		if (s[L] == s[L] % 10) {
			sum += i;
		}
	}
	cout << sum;
}
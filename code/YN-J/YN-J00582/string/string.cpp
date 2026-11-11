#include <bits/stdc++.h>
using namespace std;
const long long N = 1e9 + 10;
long long n;
int a[2000010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	char x[2000010], b;
	long long k = 0, l = 1, f = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b;
		for (long long j = 1; j <= a[i]; j++) {
			k++;
			x[k] = b;
		}
	}
	l = k;
	for (long long i = 1; i <= l / 2; i++) {
		if (x[i] != x[k]) {
			f++;
		}
		k--;
	}
	cout << f;
	return 0;
}
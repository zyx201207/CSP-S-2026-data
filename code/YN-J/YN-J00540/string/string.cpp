#include <bits/stdc++.h>
using namespace std;
string a;
long long n, x, sm, k;
char s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> s;
		k += x;
		for (int j = 1; j <= x; j++) {
			a += s;
		}
	}
	for (int i = 0; i < k / 2; i++) {
		if (a[i] != a[k - i - 1])
			sm++;
	}
	cout << sm;

	return 0;
}
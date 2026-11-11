#include <bits/stdc++.h>
using namespace std;
long long ans, n, x, k;
string s;
char y;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> x >> y;
		for (long long j = 1; j <= x; j++) {
			s += y;
		}
		ans += x;
	}
	long long j = ans - 1;
	for (long long i = 0; i <= ans / 2; i++) {
		if (s[i] != s[j])
			k++;
		j--;
	}
	cout << k;
	return 0;
}
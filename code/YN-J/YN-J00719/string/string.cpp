#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	while (n--) {
		long long a;
		char b;
		cin >> a >> b;
		for (long long i = 1; i <= a; i++) {
			s += b;
		}
	}
	long long ans = s.size(), sum = 0;
	for (long long i = 0; i <= ans; i++) {
		if (s[i] != s[--ans])
			sum++;
	}
	cout << sum;
	return 0;
}
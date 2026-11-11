#include <bits/stdc++.h>
using namespace std;

string s;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, len = 0, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		len += a;
		string c;
		cin >> c;
		for (int j = 0; j < a; j++) {
			s += c;
		}
	}
	for (int i = 0; i < len / 2; i++) {
		if (s[i] != s[len - i - 1]) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "w", stdin);
	freopen("string.out", "r", stdout);
	long long n;
	cin >> n;
	long long ans = 0;
	string s;
	long long sum = 0;
	for (int t = 1; t <= n; t++) {
		int x;
		char y;
		cin >> x >> y;
		sum += x;
		for (int t = 1; t <= x; t++) {
			s += y;
		}
	}
	long long l = sum;
	sum /= 2;
	for (int t = 0; t < sum; t++) {
		if (s[t] != s[l - t - 1]) {
			ans++;
		}
	}
	cout << ans;
}
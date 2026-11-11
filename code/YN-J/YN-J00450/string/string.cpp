#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s;
	long long n;
	cin >> n;
	long long sum = 0;
	long long da = 0;
	for (int i = 1; i <= n; i++) {
		long long a;
		string b;
		cin >> a;
		cin >> b;
		sum += a;
		for (int j = 1; j <= a; j++) {
			s += b;
		}
	}
	for (int q = 1; q <= sum / 2; q++) {
		if (s[q] != s[sum - q]) {
			s[sum - q] = s[q];
			da++;

		}
	}
	cout << da;
	return 0;
}

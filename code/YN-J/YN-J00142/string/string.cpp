#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a, sum = 0, num = 0;
	bool f = true;
	char c;
	string s;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> c;
		for (int j = 1; j <= a; j++) {
			s += c;
		}
	}
	num = s.length();
	for (int i = 0; i <= num / 2; i++) {
		if (s[i] != s[num - i - 1]) {
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
}
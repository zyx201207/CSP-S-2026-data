#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	string s = "";
	long long l;
	string c;
	long long num = 0;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> l >> c;
		for (int j = 0; j < l; j ++) {

			s = s + c;
		}
	}
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] != s[s.size() - 1 - i]) {
			num ++;
		}
	}
	cout << num / 2;
	return 0;
}
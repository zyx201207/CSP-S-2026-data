#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "r", stdout);
	int n, ans = 0;
	string s1, s2;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		string c;
		cin >> a >> c;
		for (int j = 1; j <= a; j++) {
			s1 += c;
		}
	}
	if (s1.size() % 2 == 0) {
		for (int i = 0; i < s1.size() / 2; i++) {
			s2 += s1[i];
		}
		for (int i = 0; i < s1.size() / 2; i++) {
			s2 += s1[s1.size() / 2 - i - 1];
		}
	} else {
		for (int i = 0; i <= s1.size() / 2; i++) {
			s2 += s1[i];
		}
		for (int i = 0; i < s1.size() / 2; i++) {
			s2 += s1[s1.size() / 2 - i - 1];
		}
	}
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] != s2[i]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
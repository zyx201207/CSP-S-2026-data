#include <bits/stdc++.h>
using namespace std;

int a[1001] = {0};
char c[1001];

int main() {
	freopen("sring.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
		for (int j = 0; j < a[i]; j++) {
			s += c[i];
		}
	}
	int cnt = 0;
	for (int j = 0, p = s.size(); j < s.size(), p >= 0; j++, p--) {
		if (s[j] != s[p]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
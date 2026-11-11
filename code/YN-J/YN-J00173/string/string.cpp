#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	int a;
	char b;
	int cnt1 = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		for (int j = 1; j <= a; j++) {
			s[cnt1] = b;
			cnt1++;
		}
	}
	int ans1 = 0;
	int cnt2 = cnt1 - 1;
	for (int i = 0; i < cnt2 / 2 ; i++) {
		if (s[i] != s[cnt2 - i]) {
			ans1++;
		}
	}
	cout << ans1;
	return 0;
}
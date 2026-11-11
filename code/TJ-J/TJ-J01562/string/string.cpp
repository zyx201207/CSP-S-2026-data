#include <bits/stdc++.h>
using namespace std;
int a[200000];
char c[200000];

int main() {
	freopen("a.in""string""std.in");
	freopen("a.out""string""std.out");
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> c[i];
	}
	string s;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i]; j++) {
			s += c[i];
		}
	}
	int l = s.size();
	int ans = 0;
	for (int i = 0; i < l / 2; i++) {
		if (s[i] != s[l - 1 - i]) {
			ans++;
		}
	}
	if (ans == 0) {
		cout << 0;
	} else {
		cout << ans;
	}
	return 0;
}
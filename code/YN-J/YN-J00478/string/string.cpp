#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 10;
int a[MAXN];

bool hw(string s) {
	int i = 0, j = s.size() - 1;
	while (i <= j) {
		if (s[i] != s[j]) {
			return false;
		} else {
			i++;
			j--;
		}
	}
	return true;
}

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> a[i] >> c;
		for (int j = 1; j <= a[i]; j++) {
			s += c;
		}
	}
	if (hw(s)) {
		cout << 0;
		return 0;
	}
	int cnt = 0;
	int l = 0, r = s.size() - 1;
	while (l <= r) {
		if (s[l] == s[r]) {
			l++, r--;
			continue;
		}
		cnt++;
		l++, r--;
	}
	cout << cnt << endl;
	return 0;
}
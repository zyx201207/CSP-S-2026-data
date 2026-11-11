#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, ans;
string s;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		pair<int, char> s_;
		cin >> s_.first >> s_.second;
		for (int j = 0; j < s_.first; j++) s.push_back(s_.second);
	}
	for (int i = 0; i < s.size() >> 1; i++) {
		if (s[i] != s[s.size() - 1 - i]) ans++;
	}
	cout << ans;
	return 0;
}


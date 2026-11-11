#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

bool hw(string s) {
	string s1 = s;
	reverse(s.begin(), s.end());
	return s1 == s;
}

string s;
int n, m, cnt;
char a;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m >> a;
		for (int j = 1; j <= m; j++) {
			s += a;
		}
	}
	if (hw(s)) {
		cout << 0;
	} else {
		int l = 0, r = s.size();
		while (!hw(s)) {
			s[r] = s[l];
			cnt++;
			l++;
			r--;
		}
		cout<<cnt;
	}
	return 0;
}
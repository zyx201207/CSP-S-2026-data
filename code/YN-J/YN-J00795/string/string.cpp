#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s = "";
int ans = 0;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	while (n --) {
		int num;
		char zf;
		cin >> num >> zf;
		for (int i = 1; i <= num; i ++) {
			s += zf;
		}
	}
	int x = s.size();
	int l = 0;
	int r = x - 1;
	while (l < r) {
		if (s[l] != s[r]) {
			ans ++;
		}
		l ++;
		r --;
	}
	cout << ans;
	return 0;
}
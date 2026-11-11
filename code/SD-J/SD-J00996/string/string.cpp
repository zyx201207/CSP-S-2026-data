#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

struct str {
	int a;
	char b;
} s[200010];
int n, l;
int ans;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].a >> s[i].b;
		l += s[i].a;
	}
	int le = 1, ri = n;
	while(le < ri) {
		if (s[le].a == s[ri].a) {
			if (s[le].b != s[ri].b) {
				ans += s[le].a;
			}
			le++;
			ri--;
		}
		if (s[le].a < s[ri].a) {
			if (s[le].b != s[ri].b) {
				ans += s[le].a;
			}
			s[ri].a -= s[le].a;
			le++;
		}
		if (s[le].a > s[ri].a) {
			if (s[le].b != s[ri].b) {
				ans += s[ri].a;
			}
			s[le].a -= s[ri].a;
			ri--;
		}
	}
	cout << ans;
	return 0;
}

#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

const int N = 2e5 + 23;

int n;
pair<int,char> a[N];
int ans;
int len;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		if (a[i].se != a[i - 1].se && i != 1) flag = 0;
	}
	if (flag) {
		cout << 0;
		return 0;
	}
	string s;
	for (int i = 1; i <= n; i++) {
		s += string(a[i].fi, a[i].se);
	}
	int sz = s.size();
	for (int i = 0; i < sz / 2; i++) {
		if (s[i] != s[sz - i - 1]) ans++;
	}
	cout << ans;
	return 0;
}

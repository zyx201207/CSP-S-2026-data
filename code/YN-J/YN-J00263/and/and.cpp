#include <bits/stdc++.h>//Oh Chinese can't fly в╧╩Зак
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m, ans, mn;
map<int, int>mp;

struct sephiroth {
	int num;
	string s;
} a[N];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	if (n <= 2000) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i].num;
			mn = max(mn, a[i].num);
			if (i == 1)
				ans = a[i].num;
			ans &= a[i].num;
		}
		if (m == 1) {
			cout << mn << "\n";
		}
		if (m == n) {
			cout << ans << "\n";
		}
		if (m == 2) {
			ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					ans = max(ans, a[i].num & a[j].num);
				}
			}
			cout << ans << "\n";
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i].num;
		int hh = a[i].num;
		while (hh > 0) {
			if (hh % 2 == 1)
				a[i].s += "1";
			else
				a[i].s += "0";
			hh /= 2;
		}
		string t = "";//CCF orz orz orz orz orz
		for (int j = 0; j < a[i].s.length(); j++) {
			t += a[i].s[j];
			if (a[i].s[j] == '1') {
				int lst = 1, h = 0;
				for (int k = 0; k < t.length(); k++) {
					if (t[k] == '1') {
						h += lst;
					}
					lst *= 2;
				}
				mp[h]++;
				if (mp[h] >= m) {
					ans = max(ans, h);
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
/*
5 3
31 3 1 15 7

*/
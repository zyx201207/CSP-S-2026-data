#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005], b[300005];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	string s = "";
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int k = 1; k <= n; k++) {
		s = "";
		s += char(a[k] + '0');
		int d = 0;
		for (int i = k + 1; i <= n; i++) {

			int c = s.find(char(a[i] + '0'));
			if (c >= 0 && c <= d) {
				s.erase(c, n - c);
			}
			s = s + char(a[i] + '0');
			d = s.size();
		}
		d = s.size();
		for (int i = 0; i <= d - 1; i++) {
			b[s[i] - '0']++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << b[i] << " ";
	}
	return 0;
}
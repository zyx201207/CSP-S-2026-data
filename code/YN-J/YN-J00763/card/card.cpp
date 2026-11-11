#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, sum[300005];
string s;
string a[500005];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
	}
	for (int j = 1; j <= n; j++) {
		string sc = "";
		for (int i = j; i <= n; i++) {
			int pos = sc.find(a[i]);
			cout << pos << " ";
			if (pos == -1) {
				sc += a[i];
			} else {
				sc.erase(pos + 1);
			}
		}
		for (int i = 0; i < sc.size(); i++) {
			int shu = sc[i] - '0';
			sum[shu]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << sum[i] << " ";
	}
	return 0;
}

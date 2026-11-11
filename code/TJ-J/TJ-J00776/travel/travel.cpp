#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	string a, b, c, d, ans = "0000";
	cin >> a >> b >> c >> d;
	if (a == c) {
		ans[0] = '1';
		if (b.substr(0, 2) == d.substr(0, 2)) {
			ans[1] = '1';
			if ( (b[2] <= 'C') == (d[2] <= 'C') ) {
				ans[2] = '1';
				if (b > d) swap(b, d);
				if ((b[2] == 'A' && d[2] == 'B')
					|| (b[2] == 'B' && d[2] == 'C')
					|| (b[2] == 'D' && d[2] == 'F')) {
						ans[3] = '1';
					}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

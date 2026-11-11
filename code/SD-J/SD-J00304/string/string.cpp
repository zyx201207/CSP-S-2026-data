#include <bits/stdc++.h>
#define fi first
#define se second
#define pic pair<int, char>
#define ll long long

using namespace std;

int n;
deque<pic> a;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		char c;
		cin >> x >> c;
		pic y(x, c);
		a.push_back(y);
	}
	ll ans = 0;
	while (!a.empty()) {
		if ((int)a.size() == 1)
			break;
		auto &x = a.front(), &y = a.back();
		if (y.se == x.se) {
			if (x.fi > y.fi) {
				x.fi -= y.fi;
				a.pop_back();
			}
			else if (a.front().fi < y.fi) {
				y.fi -= x.fi;
				a.pop_front();
			}
			else if (x.fi == y.fi) {
				a.pop_front();
				a.pop_back();
			}
		}
		else {
			if (x.fi > y.fi) {
				ans += y.fi;
				x.fi -= y.fi;
				a.pop_back();
			}
			else if (y.fi > x.fi) {
				ans += x.fi;
				y.fi -= x.fi;
				a.pop_front();
			}
			else if (x.fi == y.fi) {
				ans += x.fi;
				a.pop_front();
				a.pop_back();
			}
		}
	}
	cout << ans << '\n';
}

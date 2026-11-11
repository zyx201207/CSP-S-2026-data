#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll ans = 0, aaa;

struct node {
	ll a;
	char b;
} a1[10000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	bool flag = 1;
	cin >> a1[0].a >> a1[0].b;
	for (int i = 1; i < n; i++) {
		cin >> a1[i].a >> a1[i].b;
		if (a1[i].b != a1[i - 1].b)
			flag = 0;
	}
	if (flag) {
		cout << '0';
		return 0;
	}
	int r = 0, l = n - 1;
	while (r < l) {
//		aaa = a1[n / 2].a;
		if (a1[r].b != a1[l].b) {
			ans += min(a1[r].a, a1[l].a);
			a1[r].a -= min(a1[r].a, a1[l].a);
			a1[l].a -= min(a1[r].a, a1[l].a);
			if (a1[r].a == 0)
				r++;
			if (a1[l].a == 0)
				l--;
		} else {
			if (a1[r].a == a1[l].a) {
				r++;
				l--;
			} else if (a1[r].a > a1[l].a) {
				a1[r].a -= a1[l].a;
				l--;
			} else {
				a1[l].a -= a1[r].a;
				r++;
			}
		}
	}
//	if (n % 2 != 0) {
//		ans -= aaa;
//	}
	cout << ans;
	return 0;
}
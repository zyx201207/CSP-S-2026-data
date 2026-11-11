#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
ll n;

struct node {
	ll m;
	char a;
} q[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> q[i].m >> q[i].a;
	}
	ll ans = 0, cnt = 0;
	ll l = 1, r = n;
	while (l < r) {
		if (q[l].a == q[r].a) {
			if (q[l].m > q[r].m) {
				q[l].m -= q[r].m;
				r--;
			} else if (q[l].m < q[r].m) {
				q[r].m -= q[l].m;
				l++;
			} else {
				l++;
				r--;
			}
		} else {
			if (q[l].m < q[r].m) {
				ans += q[l].m;
				q[r].m -= q[l].m;
				l++;
			} else if (q[l].m > q[r].m) {
				ans += q[r].m;
				q[l].m -= q[r].m;
				r--;
			} else {
				ans += q[r].m;
				l++;
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}
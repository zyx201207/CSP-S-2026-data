#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;

ll n, a[N];
char c[N];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (ll i = 1; i <= n; i ++) cin >> a[i] >> c[i];
	
	ll ans = 0, dl = a[1], dr = a[n], l = 1, r = n;
	while (1) {
		if (dl >= dr) {
			ans += (c[r] != c[l]) * dr;
			dl -= dr;
			dr = a[-- r];
		}
		else {
			ans += (c[r] != c[l]) * dl;
			dr -= dl;
			dl = a[++ l];
		}
		if (l == r) break;
	}

	cout << ans << endl;
	return 0;
}

// 不要有压力，你去年已经拿过 J 1= 了
// 加油冲 AK
// 我相信你 Cute_zsz ！！！
// RP ++ ！！！！！

// 20min 


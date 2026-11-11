#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
typedef long long ll;
const ll INF = 1e18;
ll n, m, a[N], s[N];
ll l, r;
bool chk(ll num) {
	ll msum = INF, curs = 0;
	ll p = num / 2;
	for(int i=1; i+num-1<=n; ++i) {
		curs = 0;
		ll L = i, MID = i + p - 1, R = i + num - 1;
		MID = R;
		curs += (MID - L + 1) * a[MID] - (s[MID] - s[L - 1]);
		curs += (s[R] - s[MID]) - (R - MID) * a[MID];
		msum = min(msum, curs);
	}
	return msum <= m;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i=1; i<=n; ++i) {
		s[i] = s[i - 1] + a[i];
	}
	l = 0, r = n;
	while(l < r) {
		ll mid = (l + r + 1) >> 1;
		if(chk(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
	return 0;
} 

#include <bits/stdc++.h>
#define ll long long
#define int register int
#define db double
#define pii pair<ll,ll>
#define mpi make_pair
#define fir first
#define sec second
#define AKIOI ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define AKNOI return 0
using namespace std;
const ll MAXN = 1e5+5;
ll a[MAXN], s[MAXN], n, m, d;

ll quickpow(ll under, ll up) {
	if (up % 2 == 1)
		return under * quickpow(under * under, (up - 1) / 2);
	else
		return quickpow(under * under, up / 2);
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	AKIOI;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);

	s[1] = 0;

	for (int i = 2; i <= n; i++) {
		s[i] = s[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	}

	ll ans = upper_bound(s + 1, s + n + 1, m) - s;

	cout << ans - 1;

	AKNOI;
}
//我把结论看出来了！！！
/*
5 5
1 2 4 8 9

3

5 8
-3 -1 2 2 7

4
*/
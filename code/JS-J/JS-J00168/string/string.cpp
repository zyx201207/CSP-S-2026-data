#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
const int N = 200010;

int n, L, ans;
pair<int, char> a[N]; 

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		L += a[i].fi;
	}
	int l = 0, r = L + 1, lpos = 1, rpos = n;
	while(l < r) {
		//cout << lpos << ' ' << rpos << ' ' << l << ' ' << r << ' ' << ans << '\n';
		int x = a[lpos].fi, y = a[rpos].fi;
		int delta = min(x, y);
		if(a[lpos].se != a[rpos].se)
			ans += delta;
		a[lpos].fi -= delta, a[rpos].fi -= delta;
		l += delta, r -= delta;
		if(a[lpos].fi == 0)
			lpos++;
		if(a[rpos].fi == 0)
			rpos--;
		if(lpos >= rpos)
			break ;
	}
	cout << ans << '\n';
	return 0;	
}
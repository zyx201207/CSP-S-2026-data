#include <bits/stdc++.h>
#define ll long long
//#define debug(x) cout << #x << ' ' << x << '\n'; 
using namespace std;
int main() {
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<ll>ve(n + 1), pre(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> ve[i];
	}
	sort(ve.begin() + 1, ve.end());
	for (int i = 1;i <= n;i++) {
		pre[i] = pre[i - 1] + ve[i];
	}
	auto check = [&](int len) {
		ll minn = 1e18;
		for (int l = 1, r = len;r <= n;l++, r++) {
			minn = min<ll>(minn, 1ll * ve[r] * len - 1ll * (1ll * pre[r] - pre[l - 1]));
		}
		return int(minn <= m);
	};
	
//	debug(check(3));
	
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if(check(mid)) {
			l = mid;
		}else{
			r = mid - 1;
		}
	} 
	cout << l << '\n';
//	debug(r);
	return 0;
} 

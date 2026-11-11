#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[500005], pre[500005], m;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int  i =1;i <= n;i ++)
		pre[i] = pre[i-1] + a[i];
	ll ans = 1;
	for(ll l = 1;l <= n;l ++) {
		for(ll r = l + ans;r <= n;r ++) {
			ll t = a[r]*(r - l) - (pre[r - 1] - pre[l - 1]);
			if(t <= m) {
				ans = max(r - l + 1, ans);
			}
			else break ;
		}
	}
	cout << ans;
	return 0;
}
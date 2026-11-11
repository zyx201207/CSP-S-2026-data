#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 5e5 + 5;
ll a[M], pre[M], ls, rs;
ll n, m;
ll ans;
bool check(ll x){
	for (ll i = x; i <= n; i++ ){
		if ((a[i] * x - pre[i] + pre[i - x]) <= m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++ ) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i++ ) pre[i] = pre[i - 1] + a[i];
	ls = 1;rs = n;
	while (ls <= rs){
		ll mid = (ls + rs) >> 1;
		if (check(mid)){
			ans = mid;
			ls = mid + 1;
		}
		else rs = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}

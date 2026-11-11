#include <vector>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define fi first
#define se second
#define pii pair<ll , ll>
#define mk make_pair
using namespace std;
const int N = 5e5 + 10;
ll n , m , a[N] , sum[N] , ans;
ll read(){
	ll x = 0 , w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') w = (ch == '-' ? -1 : 1) , ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0' , ch = getchar();
	return x * w;
}
ll get_sum(ll i , ll x){
	return sum[i - 1] - sum[i - x - 1];
}
signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	for (int i = 1;i <= n;i ++) sum[i] = sum[i - 1] + a[i];
	for (int i = 1;i <= n;i ++){
		ll l = 1 , r = i - 1 , mid , res = 0;
		while (l <= r){
			ll mid = (l + r) / 2;
			if (a[i] * mid - get_sum(i , mid) <= m) l = mid + 1 , res = mid;
			else r = mid - 1;
		}
		ans = max(res + 1 , ans);
	}
	cout << ans << "\n";
	return 0;
}
/*

*/
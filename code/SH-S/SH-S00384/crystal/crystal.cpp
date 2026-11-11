#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n;
ll m,a[N],sm[N];
bool check(ll x){
	ll res = LONG_LONG_MAX;
	for (ll i = 1;i + x - 1 <= n;i++){
		res = min(res,x * a[i + x - 1] - (sm[i + x - 1] - sm[i - 1]));
	}
	return res <= m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++) sm[i] = sm[i - 1] + a[i];
	ll l = 1,r = n,mid,ans;
	while (l <= r){
		mid = l + r >> 1;
		if (check(mid)) l = mid + 1,ans = mid;
		else r = mid - 1;
	}
	cout << ans;
}

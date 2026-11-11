#include <bits/stdc++.h>
#define ll long long
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1e5 * 5 + 10;
ll n,m;
ll a[N];
bool check(long long ans){
	long long pd = 0;
//	cout << ans << ' ';
	for(ll i = 1;i <= n - ans + 1;i ++){
		pd = 0;
		for (ll j = i;j < i + ans - 1;j ++){
			pd += a[i + ans - 1] - a[j];
			if(pd > m) break;
		}
		if(pd <= m) return true;
	}                                                      
	return false;
}
int main(){
	FIO
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	ll l = 1,r = n;
	for (int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1,a + n + 1);
//	for(int i = 1; i<= n;i ++) cout << a[i] << ' ';
	while(l + 1 < r){
		ll mid = (l + r) / 2;
	//	cout << mid << ' ';
		if(check(mid)) l = mid;
		else r = mid;
	}
	if(check(r)) cout << r;
	else cout << l;
	return 0;
}
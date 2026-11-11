#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 200010;
ll n,m,a[N],k;
bool flag[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(ll i = 1 ; i <= n ; i++) cin >> a[i];
	k = n;
	for(ll i = 30 ; i >= 0 ; i--){
		ll cnt = 0;
		for(ll j = 1 ; j <= n ; j++){
			if(flag[j]) continue;
			cnt += bool(a[j] & (1ll << i));
		}
		if(cnt >= m){
			for(ll j = 1 ; j <= n ; j++){
				if(!bool(a[j] & (1ll << i))) flag[j] = 1;
			}
		}
	}
	ll ans = (1ll << 31)-1;
	for(ll i = 1 ; i <= n ; i++){
		if(!flag[i]) ans &= a[i];
	}
	cout << ans << endl;
	return 0;
}


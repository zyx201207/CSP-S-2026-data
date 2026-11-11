#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+9;
ll n,m;
ll a[N];
ll s[N];
ll ans = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1;i <= n;i++){
		cin >> a[i];
		//cout << s[i] << endl;
	}
	sort(a+1,a+n+1);
	for(ll i = 1;i <= n;i++){
		s[i] = s[i-1]+a[i];		
	}
	for(ll i = 1;i <= n;i++){
		ll l = 1,r = i;
		ll k;
		while(l<=r){
			ll mid = (r-l)/2+l;
			ll w = mid*a[i]-s[i]+s[i-mid];
			//cout << w << endl;
			if(w<=m){
				l = mid+1,k = mid;
				//cout << i << ' ' << mid << " ok" << endl;
			}
			else r = mid-1;
		}
		//cout << "i:" << k << endl; 
		ans = max(ans,k);
	}
	cout << ans << endl;
	return 0;
}


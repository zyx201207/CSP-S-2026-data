#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

void fast_io(){
	ios::sync_with_stdio(0);
	cin.tie(0) ,cout.tie(0);
}

const ll kMaxN = 5e5 + 7;

ll m;
ll n , a[kMaxN];
ll sum[kMaxN];

void solve(){
	cin>>n>>m;
	for(int i = 1 ; i <= n ; i++) cin>>a[i];
	sort(a + 1 , a + 1 + n);
	for(int i = 1 ; i <= n ; i++) sum[i] = sum[i - 1] + a[i];
	ll j = 1;
	ll ans = 0;
	for(int i = 1 ; i <= n ; i++){
//		ll s = i * a[i];
		
		while(j < i && (i - j + 1) * a[i] - (sum[i] - sum[j - 1]) > m) j++;
//		while(s - (sum[i] - sum[j - 2]) <= m) j--;
		ans = max(ans , i - j + 1);
	}
//	cout<<j;
//	cout<<j<<" ";
	cout<<ans;
}

int main(){
	fast_io();
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	solve();
	return 0;
}


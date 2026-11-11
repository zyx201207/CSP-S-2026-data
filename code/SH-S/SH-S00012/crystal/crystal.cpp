#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 5e5+10;
int n;
ll m;
ll ans;
vector<ll> f(MAXN);
vector<ll> a(MAXN);
ll lowerbound(ll i,ll q){
	ll l=1,r=i;
	ll res = 0;
	while(l <= r){
		ll mid = (l+r)>>1;
		if (f[mid]+a[i]*mid>=q){
			r = mid-1;
			res = mid;
		}
		else l = mid+1;
	}
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a.begin()+1,a.begin()+1+n); 
	for (int i=n;i>=1;i--){
		f[i] = f[i+1]+a[i];
	}
	for (int i=1;i<=n;i++){
		ll j = lowerbound(i,a[i]*i+f[i]-m);
		if (j == 0) continue;
		ans = max(ans,i-j+1);
	}
	cout << ans;
	return 0; 
} 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in" ,"r" ,stdin);
	freopen("crystal.out" ,"w" ,stdout);
	ll n ,m ,ans = LLONG_MIN;
	cin>>n>>m;
	vector<ll> a(n+1) ,s(n+1);
	for(ll i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1 ,a.end());
	function<bool(ll ,ll)> check = [&](ll l ,ll r){
		if((r-l)*a[r]-s[r-1]+s[l-1] > m){
			return false;
		}
		else{
			return true;
		}
	};
	function<ll(ll)> find = [&](ll y){
		ll l = 1 ,r = y;
		ll mid;
		while(l < r){
			mid = l + (r-l) / 2;
			if(check(mid ,y)){
				r = mid;
			}
			else{
				l = mid + 1;
			}
		}
//		cout<<mid<<" "<<y<<"\n";
		return y-r+1;
	};
	for(ll i = 1;i <= n;i++){
		s[i] = s[i-1]+a[i];
	}
	for(ll i = 1;i <= n;i++){
		ans = max(find(i) ,ans);
	}
	cout<<ans;
	return 0;
}
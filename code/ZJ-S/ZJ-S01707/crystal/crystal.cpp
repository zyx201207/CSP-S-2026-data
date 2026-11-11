#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, a[500005];

bool check(ll mid){
	ll ed = mid, nowneed = 0;
	ll ret = 4e15;
	for(int i = 1;i <= ed;i++){
		nowneed += a[ed]-a[i];
	}
	ret = min(ret, nowneed);
	while(ed < n){
		nowneed += (a[ed+1]-a[ed])*mid;
		nowneed -= a[ed]-a[ed-mid+1];
		ed++;
		ret = min(ret, nowneed);
		//cout << nowneed << endl;
	}
	return ret <= m;
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	ll l = 1, r = n, ans = 0;
	while(l <= r){
		ll mid = (l+r)>>1;
		if(check(mid)){
			l = mid+1;
			ans = mid;
		}else{
			r = mid-1;
		}
	}
	cout << ans << endl;
	return 0;
}
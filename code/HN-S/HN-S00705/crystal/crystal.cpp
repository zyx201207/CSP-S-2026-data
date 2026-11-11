#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 5;
const ll INF = 1e18;

ll n, m, a[MAXN], dif;

bool check1(ll x){
	ll ans = 0;
	for(int i = 1; i < x; i++){
		ans += a[x] - a[i]; 
	}
	return ans <= m;
}

bool check(){
	bool f = 1;
	for(int i = 2; i <= n; i++){
		if(a[i] - a[i - 1] != dif){
			f = 0;
			break;
		}
	} 
	return f;
}

namespace subtasksq{
	ll sum = 0, cnt = 0, k = 0;
	void solve(){
		for(int i = 1; sum <= m && cnt <= n; i++){
			sum += i * dif;
			cnt++;
		}
		cout << cnt;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	dif = a[2] - a[1]; 
	if(check()){
		subtasksq::solve();
	}
	sort(a + 1, a + n + 1);
	ll L = 1, R = n, ans = -INF;
	while(L <= R){
		ll mid = (L + R) >> 1;
		if(check1(mid)){
			L = mid + 1;
			ans = mid;
		}else{
			R = mid - 1;
		} 
	}
	cout << ans;
	return 0;
} 

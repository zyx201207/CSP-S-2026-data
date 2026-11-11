//SN-S00448ÕÅò«Òã 
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ll n, m, ans = 1;
	cin >> n >> m;
	vector <ll> a(n + 1, 0);
	for(int i = 1; i <= n ; i++) cin >> a[i];
	
	sort(a.begin(), a.end());

	for(int i = n; i >= 2; i--){
		ll lm = 0;
		ll lans = 1;
		for(int j = i - 1; j >= 1 ; j--){
			lm += a[i] - a[j];
			if(lm > m) break;
			lans++;
		}
		ans = max(ans, lans);
	}
	
	cout << ans;
}

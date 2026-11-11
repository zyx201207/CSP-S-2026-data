#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005];
ll pre[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	ll n, m;
	cin >> n >> m;
	for (ll i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1,a+n+1);
	//bool flag = 0;
	for (int i = 1; i <= n; i++){
		pre[i] = pre[i-1] + a[i];
//		if (i > 1 && i == 2){
//			cha = a[i] - a[i-1];
//		}else{
//			if (a[i] - a[i-1] != cha){
//				flag = 1;
//			}
//		}
	}
//	if (flag == 1){
//		ll f = sqrt(m);
//	}
	ll mx = 0;
	for (ll i = 1; i <= n; i++){
//		for (ll j = i; j >= 1; j--){
//			ll need = a[i] * (i - j + 1) - pre[i]+ pre[j-1];
//			if (m >= need){
//				mx = max(mx, i- j + 1);
//				ind = i;
//			}
//		}
		ll l = 1, r = i;
		while(l <= r){
			ll mid = l + (r - l) / 2;
			if (a[i] * mid - pre[i]+ pre[i - mid] > m){
				r = mid - 1;
			}else{
				mx = max(mx ,mid);
				l = mid + 1;
				
			}
		}
	}
	
	cout << mx;
	return 0;
}

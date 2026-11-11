#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , m , a[500005] , ans;
bool ism = 1;
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	for(int i = 3 ; i <= n ; i ++){
		if(abs(a[i] - a[i - 1]) != abs(a[i - 1] - a[i - 2])){
			ism = 0;
		}
	}
	if(ism){
		ll delta = abs(a[2] - a[1]);
		ll x = m / delta;
		ll v = sqrtl(2 * x);
		if(v * (v + 1) <= 2 * x){
			cout << min(v + 1 , n);
		}
		else{
			cout << min(v , n);
		}
		return 0;
	}
	
	for(int i = n ; i >= 1 ; i --){
		if(i <= ans){
			cout << ans;
			return 0;
		}
		ll cnt = 1 , q = 0;
		for(int j = i - 1 ; j >= 1 ; j --){
			if(q + a[i] - a[j] <= m){
				q += a[i] - a[j];
				cnt ++;
			}
			else{
				break;
			}
		}
		ans = max(ans , cnt);
	}
	cout << ans;
	return 0;
}
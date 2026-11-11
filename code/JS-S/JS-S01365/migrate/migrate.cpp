#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c , t , n , d , a[2000005] , ans;
void solvea(){
	ll e = a[2] - a[1];
	ll l = d / e , y = d % e;
	if(l == 0 or (l == 1 and y == 0)){
		cout << 0 << '\n';
		return;
	}
	ll p = l * 2;
	cout << max(n - p + 1 , 0ll) << '\n';
}
int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	cin >> c >> t;
	while(t --){
		cin >> n >> d;
		ans = 0;
		for(int i = 1 ; i <= n ; i ++){
			cin >> a[i];
		}
		if(c == 11 or c == 12){
			solvea();
			continue;
		}
		for(int i = 1 ; i < n ; i ++){
			for(int j = i + 2 ; j <= n ; j ++){
				int k , d1 = 0 , d2 = 0;
				for(k = i + 1 ; d1 <= d and k <= j ; k ++){
					d1 += a[k] - a[k - 1];
				}
				if(k == j and d1 <= d){
					continue;
				}
				d1 -= a[k] - a[k - 1];
				k --;
				for(int v = k ; v <= j ; v ++){
					d2 += a[v] - a[v - 1];
				}
				if(d2 > d){
					continue;
				}
				k --;
				d1 -= a[k] - a[k - 1];
				d2 += a[k] - a[k - 1];
				if(d2 > d or k <= i){
					continue;
				}
				k --;
				d1 -= a[k] - a[k - 1];
				d2 += a[k] - a[k - 1];
				if(k <= i or d2 <= d){
					continue;
				}
				ans ++;
				//cout << i << ' ' << j << endl;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
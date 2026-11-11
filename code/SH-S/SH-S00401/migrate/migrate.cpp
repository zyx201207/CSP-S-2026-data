#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c , t , n , d , ans , x[2000009] , cnt[2000009] , dst[2000009];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(ll i = 1; i <= n; i++){
			cin >> x[i];
		}
		ans = 0;
		for(ll i = 1; i < n; i++){
			dst[i] = 0;
			cnt[i] = 1;
			for(ll k = i+1; k <= n; k++){
				dst[k] = 1e11;
				cnt[k] = 0;
				for(ll j = k-1; j >= i; j--){
					if(x[k] - x[j] <= d){
						if(dst[k] > dst[j] + 1){
							dst[k] = dst[j] + 1;
							cnt[k] = cnt[j];
						}
						else if(dst[k] == dst[j] + 1){
							cnt[k] += cnt[j];
						}
					}
					else break;
				}
				if(cnt[k] == 2){
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

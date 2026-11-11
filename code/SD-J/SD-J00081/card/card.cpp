#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10, M = 3e5 + 5;
ll a[N], a1[N];
ll jl[M], ans[M];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ll n, m, T;
	scanf("%lld %lld", &n, &m);
	T = n;	
	for(ll i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	while(T--){
		memset(jl, 0, sizeof(jl));
		ll js = n - T;
		ll cnt = 0;
		for(ll i = js; i <= n; i++){
			if(jl[a[i]] == 0){
				cnt ++;
				jl[a[i]] = cnt;
				a1[cnt] = a[i];
			}else{
				ll old = jl[a[i]];
				for(int j = jl[a[i]]; j <= cnt; j++){
					jl[a1[j]] = 0;
					a1[j] = 0;
				}
				cnt = old;
				jl[a[i]] = cnt;
				a1[cnt] = a[i];
			}
		}
		for(ll i = 1; i <= cnt; i++){
			ans[a1[i]]++;
		}
	}
	for(ll i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}

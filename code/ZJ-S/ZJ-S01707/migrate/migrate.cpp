#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, c, t, x[2000005], d;
ll dp[2000005], cnt[2000005], cont;
namespace Brute{
	ll toid(ll id, ll st){
		ll find = x[id]-d;
		ll idx = lower_bound(x+st, x+1+n, find)-x;
		return idx;
	}
	void solve(){
		scanf("%lld%lld", &n, &d);
		for(int i = 1;i <= n;i++){
			scanf("%lld", &x[i]);
		}
		ll ans = 0;
		for(int st = 1;st < n;st++){
			cnt[st] = 1;
			ll tmp = 0;
			for(int i = st+1;i <= n;i++){
				cnt[i] = 0;
				dp[i] = dp[toid(i, st)]+1;
				for(int j = toid(i, st);j < i;j++){
					if(dp[j] == dp[toid(i, st)]){
						cnt[i] += cnt[j];
						cont++;
					}
				}
				if(cnt[i] == 2) tmp++;
				//cout << cnt[i] << ' ';
			}
			//cout << endl;
			ans += tmp;
		}
		printf("%lld\n", ans);
	}
}

namespace partA{
	void solve(){
		scanf("%lld%lld", &n, &d);
		for(int i = 1;i <= n;i++){
			scanf("%lld", &x[i]);
		}
		ll shared = x[2]-x[1];
		ll need = d/shared;
		if(need <= 1 || d == shared){
			printf("0\n");
			return;
		}
		ll ans = (n-need+max(n-2*need+1, 1ll))/2*(n-need-max(1ll, n-2*need+1)+1);
		printf("%lld\n", ans);
	}
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while(t--){
		if(c >= 0 && c <= 10) Brute::solve();
		else partA::solve();
		//partA::solve();
	}
	//printf("%lld\n", cont);
	return 0;
}
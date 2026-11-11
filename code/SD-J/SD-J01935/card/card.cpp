#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 5;
const ll M = 3e5 + 5;
ll n, m;
ll dp[N], cnt[N], a[N], lst[M], ans[M];
vector<ll> res;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++ ) cin >> a[i];
	for (ll i = n; i >= 1; i-- ){
		if (!lst[a[i]]){
			dp[i] = i;
			lst[a[i]] = i;
			res.push_back(i);
		}
		else{
			dp[i] = dp[lst[a[i]]];
			cnt[lst[a[i]]]++;
		}
	}
	sort(res.begin(), res.end());
	for (ll i : res){
		ans[a[i]] += (++cnt[i]);
		cnt[dp[i + 1]] += cnt[i];
	}
	if (ans[a[n]] != n) ans[a[n]] = n;
	for (ll i = 1; i <= m; i++ ){
		cout << ans[i];
		if (i != m) cout << ' ';
	}
	return 0;
} 

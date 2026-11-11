#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 2e6 + 5;
ll a[M], idx[M], pre[M];
bool fst[M];
void solve(){
	ll n, m;
	scanf("%lld%lld", &n, &m);
	vector<ll> need;
	for (ll i = 1; i <= n; i++ ){
		scanf("%lld", &a[i]);
		need.push_back(a[i]);
		need.push_back(a[i] - m);
		need.push_back(a[i] + m);
	}
	sort(need.begin(), need.end());
	ll cnt = 0;
	map<ll, ll> in_idx;
	for (ll x : need){
		if (!in_idx[x]){
			in_idx[x] = ++cnt;
			idx[cnt] = x;
		}
	}
	memset(fst, false, sizeof fst);
	for (ll i = 1; i <= n; i++ ){
		fst[in_idx[a[i]]] = true;
	}
	for (ll i = 1; i <= cnt; i++ ){
		pre[i] = pre[i - 1] + (fst[i] == true ? 1 : 0);
	}
	ll res = 0;
//	for (ll i = 1; i <= cnt; i++ ){
//		cout << "idx[" << i << "] = " << idx[i] << ' ';
//	}
//	cout << '\n';
//	for (ll i = 1; i <= cnt; i++ ){
//		cout << "pre[" << i << "] = " << pre[i] << ' ';
//	}
//	cout << '\n';
	for (ll i = 1; i <= n - 3; i++ ){
		for (ll j = i + 3; j <= n; j++ ){
			ll sc = in_idx[a[i] + m], th = in_idx[a[j] - m];
			if (sc > th && pre[sc] - pre[th - 1] == 2) res++;
		}
	}
	cout << res << '\n';
	return; 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c, t;
	scanf("%lld%lld", &c, &t);
	while (t--){
		solve();
	}
}

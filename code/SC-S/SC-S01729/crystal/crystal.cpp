#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const ll LEN = 5e5+10;
ll ans, N, M, W[LEN], A[LEN];
bool ok(ll l, ll r){
	if((r-l+1)*W[r]-(A[r]-A[l-1]) <= M)
		return true;
	else return false;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &N, &M);
	for(ll i = 1; i <= N; i++)
		scanf("%lld", &W[i]);
	sort(&W[1], &W[N+1]);
	for(ll i = 1; i <= N; i++){
		A[i] = A[i-1]+W[i];
	} for(ll i = 1; i <= N; i++){
		ll l = 0, r = i+1;
		while(l+1 < r){
			ll mid = (l+r)/2;
			if(ok(mid, i)) r = mid;
			else l = mid;
		} ans = max(ans, i-r+1);
	} printf("%lld", ans);
	return 0;
}
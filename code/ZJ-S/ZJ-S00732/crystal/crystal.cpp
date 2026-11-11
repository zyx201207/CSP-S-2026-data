#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5 + 5;
ll n,m,ans;
ll a[N + 5],c[N + 5];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i = 1;i <= n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	ll l = 1;
	for(ll i = 1;i <= n;++i){
		c[i] = c[i-1] + a[i];
		while(l <= i && c[i] - c[l-1] < (i-l+1)*a[i]-m) ++l;
		ans = max(ans,i-l+1);
	}
	printf("%lld",ans);
	return 0;
} 
/*5 5
1 2 4 8 9*/
//Oct31==Dec25?

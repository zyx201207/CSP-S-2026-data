#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		ll m = n / 2;
		for(ll i = 1;i < n;++i){
			ll x,y;
			scanf("%lld%lld",&x,&y);
		}
		if(k >= n){
			printf("0\n");
			continue;
		} 
		if(k >= m){
			printf("1\n");
			continue;
		}
		ll l = (m - k - 1) / (k + 1) + 1;
		printf("%lld\n",l+1); 
	}
	return 0;
}

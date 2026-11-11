#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e6+10;
ll t,n,d,x[N],c;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		ll s=0,be=x[2]-x[1];
		for(ll i=3;i<n;i++){
			s+=n-i;
		}
		printf("%lld\n",s);
	}
	return 0;
}

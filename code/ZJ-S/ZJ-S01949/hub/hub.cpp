#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,t;
	scanf("%lld%lld",&c,&t);
	while(t--){
		ll n,k;
		scanf("%lld%lld",&n,&k);
		ll s=-1;
		for(int i=0;i<n;i++){
			ll v,u;
			scanf("%lld%lld",&v,&u);
			s=s==-1?v:s;
		}printf("%lld\n",s);
	}
	return 0;
}


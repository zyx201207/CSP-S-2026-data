#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
const ll Max=1e18+5;
ll num[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	scanf("%lld%lld",&c,&t);
	while(t--){
		ll n,d;
		scanf("%lld%lld",&n,&d);
		for(int i=0;i<n;i++){
			scanf("%lld",&num[i]);
		}ll ans=num[0];
		printf("%lld\n",ans);
	}
	return 0;
}


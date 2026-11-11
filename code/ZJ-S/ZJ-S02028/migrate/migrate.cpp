#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,N,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ll n,d,x[200006];
		scanf("%lld%lld",&n,&d);
		for(int i = 0;i < n;i++){
			scanf("%lld",x + i);
		}
			if(n == 1){
				printf("0\n");
				continue;
			}
			ll dis = x[1] - x[0];
			ll o = d/dis;
			if(o == 1){
				printf("0\n");
				continue;
			}
			o = 2 * (o - 1) + 1;
			ll xds = 0;
			printf("%lld\n",max(xds,n - o));
	}
	return 0;
}

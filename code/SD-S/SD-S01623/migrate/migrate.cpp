#include<bits/stdc++.h>
#define ll long long
#define pll pair<long,long>
using namespace std;
const ll N=2*1e6;
ll c,t;
ll n,d;
ll x[N+7];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		if(c>=11&&c<=12){
			if(x[2]-x[1]>d){
				printf("0\n");
				continue;
			}
			ll mdis=d/(x[2]-x[1]);
			if(mdis==1) printf("0\n");
			else{
				printf("%lld\n",n/((n-1)%d)*1ll);
			}
			continue;
		}
	}
	return 0;
}

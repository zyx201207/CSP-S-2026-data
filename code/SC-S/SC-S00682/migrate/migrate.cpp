#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000006],dl,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;++i){
			scanf("%lld",&x[i]);
		}
		if(c==11||c==12){
			dl=x[2]-x[1];
			dl=d/dl;
			for(int i=dl+2;i<=2+dl;++i){
				ans+=n/i;
			}
			printf("%lld",ans);
		}
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10; 
ll c,t,n,d,x[N],s[N],cha;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ll ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		cha=x[2]-x[1];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=500;j++){
				ll dis=x[j]-x[i];
				if(dis%d==0){
					continue;
				}
				ll mi=ceil(1.0*dis/d);
				if(mi==2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

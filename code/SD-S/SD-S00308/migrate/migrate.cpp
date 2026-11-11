#include<bits/stdc++.h>
#define ll long long
#define N 2000005
using namespace std;
int c,t;
ll n,d;
ll x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;++i){
			scanf("%lld",&x[i]);
		}
			ll cz=x[2]-x[1];
			ll a=d/cz;
			if(n-2*a+1<0||a==0||a==1)printf("0\n");
			else printf("%lld\n",n-2*a+1);
		
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		scanf("%lld",&n);
		bool v=0;
		for(int i=1;i<=n;++i){
			scanf("%lld %lld",a[i],d);
			if(i>=3){
				if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
					v=1;
				}
			} 
		}	
		if(v==0){
			if(d<(a[n]-a[n-1])*2){
				printf("0\n");
				return 0;
			}
			if(n<=3){
				printf("0\n");
			}
			printf("%lld\n",(n-3)*(n-2)/2);
			return 0;
		}else{
			printf("%lld\n",n-1);
		}
	}
	return 0;
}


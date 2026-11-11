#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(n==1){
			printf("0\n");
			continue;
		}
	//	if(c>=11&&c<=12){
			int dd=a[2]-a[1];
			if(d<2*dd||d>=(n-1)*dd){
				printf("0\n");
				continue;
			}
			int l=2*(d/dd)-1;
			printf("%lld\n",n-l);
	//	}
	}
	return 0;
}

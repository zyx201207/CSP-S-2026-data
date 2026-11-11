//SN-S00226
#include <bits/stdc++.h>
using namespace std;
int c,T;
long long n,d;
long long a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		long long c=a[2]-a[1];
		long long t=d/c;
		if(t<=1){
			printf("0\n");
			continue;
		}
		long long ans=0;
		for(int i=4;i<=n;i++){
			if((i-1)/t+1>=2 && (i-1)%t!=0) ans++;
		}
		printf("%lld\n",ans);
		continue;
	}
	return 0;
}

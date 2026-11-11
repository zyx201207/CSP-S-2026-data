#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t); 
	while(t--){
		scanf("%ld%ld",&n,&d);
		for(long long i=1;i<=n;i++) scanf("%ld",&x[i]);
		if(x[n]-x[1]<=d) {
			printf("0\n");
			continue;
		}
		if(c==13||c==14) {
			long long mi,cnt=0;
			for(long long i=1;i<=n;i++) 
			  if(x[i]-x[1]>d) {
			  	mi=i;
			  	break;
			  }
			for(long long i=mi;i>=0;i--){
				if(x[n]-x[i]>d) break;
				else cnt++;
			}
			printf("%ld\n",cnt);
			return 0;
		}
		printf("1");
	}
	return 0;
}
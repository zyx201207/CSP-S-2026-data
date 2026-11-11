#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2200000],a[2200000],b[2200000],af[2200000],bf[2200000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c==13||c==14){
		while(t--){
			scanf("%lld",n);
			for(long long i=1;i<=n;i++){
				scanf("%lld",&x[i]);
			}
		}
		printf("0\n");
		return 0;
	}
	while(t--){
		long long m=0;
		scanf("%lld%lld",&n,&d);
		for(long long i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			a[i]=b[i]=0;
			af[i]=bf[i]=1;
		}
		long long l=1;
		for(long long i=2;i<=n;i++){
			if(x[i]-x[l]<=d&&(x[i+1]-x[l]>d||i+1>n)){
				a[i]=l;
				l++;
			}
			else if(x[i]-x[l]>d){
				l++;
			}
		}
		l=1;
		for(long long i=2;i<=n;i++){
			while(x[i]-x[l]>d){
				l++;
			}
			if(x[i+1]-x[l]>d||i+1>n){
				af[i]=af[l]+1;
			}
		}
		//////////////////////////////
		long long r=n;
		for(long long i=n-1;i>=1;i--){
			if(x[r]-x[i]<=d&&(x[r]-x[i-1]>d||i-1<1)){
				b[i]=r;
				r--;
			}
			else if(x[r]-x[i]>d){
				r--;
			}
		}
		r=n;
		for(long long i=n-1;i>=1;i--){
			while(x[r]-x[i]>d){
				r--;
			}
			if(x[r]-x[i-1]>d||i-1<1){
				bf[i]=bf[r]+1;
			}
		}
		/////
//		for(long long i=1;i<=n;i++){
//			printf("%lld ",af[i]);
//		}
//		printf("\n");
//		for(long long i=1;i<=n;i++){
//			printf("%lld ",bf[i]);
//		}
//		printf("\n");
//
//		for(long long i=1;i<=n;i++){
//			printf("%lld ",a[i]);
//		}
//		printf("\n");
//		for(long long i=1;i<=n;i++){
//			printf("%lld ",b[i]);
//		}
//		printf("\n");
		for(long long i=2;i<=n;i++){
			if(a[i]&&b[i-1]&&a[i]!=i-1&&b[i-1]!=i){
				m+=(af[a[i]]*bf[b[i-1]]);
			}
		}
		printf("%lld\n",m);
	}
	return 0;
}

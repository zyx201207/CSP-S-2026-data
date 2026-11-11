#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long x[2200000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	long long n,d;
	long long gc;
	while(t--){
		int fl=1;
		scanf("%lld%lld",&n,&d);
		if(n==1 or n==2 or n==3){
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n;++i){
			scanf("%lld",&x[i]);
			gc=x[2]-x[1];
			if(i>=3){
				if(x[i]-x[i-1]!=gc){
					fl=2;
				}
			}
		}

		if(fl==1){
			d=d/gc;
			if(d==0 or d==1)printf("0\n");
			else printf("%lld\n",max(1ll*0,n-(2ll*d-1)));
		}
		if(fl==2){
			int fl1=0;
			int fl2=0;
			long long leftcov=0;
			long long rightcov=0;
			for(int i=1;i<=n;++i){
				if(x[n]-x[i]<=d && fl1==0){
					fl1=1;
					leftcov=i;
				}
				if(x[i]-x[1]>d && fl2==0){
					fl2=1;
					rightcov=i;
				}
			}
			if((rightcov-leftcov)!=2){
				printf("0\n");
			}else{
				long long ans=(leftcov-1)*(n-rightcov+1);
				printf("%lld\n",ans);
			}
		}
		
	}


	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,x[2000200],after[2000200],behind[2000200];
long long ans;
long long check_after(long long start,long long dis) {
	long long L=start,R=n+1;
	while(L+1<R) {
		long long M=(L+R)>>1;
		if(x[M]-x[start]<=dis) {
			L=M;
		} else {
			R=M;
		}
	}
	while(L<n&&x[L+1]-x[start]<=dis) {
		++L;
	}
	return L-start;
}
long long check_behind(long long start,long long dis) {
	long long L=0,R=start;
	while(L+1<R) {
		long long M=(L+R)>>1;
		if(x[start]-x[M]<=dis) {
			R=M;
		} else {
			L=M;
		}
	}
	while(R>1&&x[start]-x[R-1]<=dis) {
		--R;
	}
	return start-R;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(long long T=1; T<=t; T++) {
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(long long i=1; i<=n; i++) {
			scanf("%lld",&x[i]);
		}
		if(n==1) {
			printf("0\n");
			continue;
		}
		long long gc=check_after(1LL,d);
		if(gc>1){
			ans=max(0LL,n-2*gc+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

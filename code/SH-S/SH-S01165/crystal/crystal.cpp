#include<cstdio>
#include<algorithm>
long long a[500005], qzh[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
 	int n, L, R, M;
 	long long m, minUse;
 	qzh[0]=0;
 	scanf("%d%lld", &n, &m);
 	for(int i=1;i<=n;i++){
 		scanf("%lld", &a[i]);
	}
	std::sort(a+1, a+n+1);
	for(int i=1;i<=n;i++){
 		qzh[i]=qzh[i-1]+a[i];
	}
	L=1, R=n;
	while(L<R){
		M=(L+R+1)>>1;
		//printf("%d %d %d\n", L, M, R);
		minUse=1e18;
		for(int i=M;i<=n;i++){
			minUse=std::min(minUse, a[i]*M-qzh[i]+qzh[i-M]);
		}
		if(minUse<=m){	
			L=M;
			//printf("+");
		}
		else{
			R=M-1;
			//printf("-");
		}
	}
	printf("%d", L);
	return 0;
}

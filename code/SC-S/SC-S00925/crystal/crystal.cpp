#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],MAX_a=INT64_MIN,MIN_a=INT64_MAX,c[100010],tmp,ans,tot;
bool flag;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		MAX_a=max(MAX_a,a[i]);
		MIN_a=min(MIN_a,a[i]);
	}
//	printf("%lld %lld",MAX_a,MIN_a);
	for(int i=MIN_a;i<=MAX_a;i++){
		for(int j=1;j<=n;j++){
			c[j]=abs(a[j]-i);
//			printf("%lld ",c[j]);
		}
//		printf("i=%lld\n",i);
		sort(c+1,c+n+1);
//		for(int j=1;j<=n;j++){
//			printf("%lld ",c[j]);
//		}
//		printf("\n");
		tmp=0;
		tot=0;
		for(int j=1;j<=n;j++){
			if(c[j]+tmp<=m){
				tmp+=c[j];
				tot++;
//				printf("tmp=%lld tot=%lld\n",tmp,tot);
			}else{
				break;
			}
		}
		ans=max(ans,tot);
	}
	printf("%lld",ans);
	return 0;
}

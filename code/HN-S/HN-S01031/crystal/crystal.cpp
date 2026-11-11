#include<bits/stdc++.h>
using namespace std;
long long n,a[500100],m,qzh[500100],ans=0;
long long Ans_now=0;
void init(){
	ans=0;
	Ans_now=0;
	for(int i=0;i<500100;i++){
		a[i]=0;
		qzh[i]=0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=0,m=0;
	scanf("%lld%lld",&n,&m);
	init();
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		Ans_now=0;
		long long L=0,R=i+1;
		while(L+1<R){
			long long M=(L+R)>>1;
			long long need=(i-M+1)*a[i]-(qzh[i]-qzh[M-1]);
			if(need<=m){
				R=M;
			}else{
				L=M;
			}
		}
		Ans_now=i-L;
		ans=max(ans,Ans_now);
	}
	printf("%lld\n",ans);
	return 0;
}

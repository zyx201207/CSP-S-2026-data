#include<bits/stdc++.h> 
using namespace std;
const int N=5.1e5;
int n;
long long m,a[N];
void file(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
void input(){
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
}
namespace subsolve{
	long long sum[N];
	void func(){
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		long long l=1,r=1,ans=0;
		for(;l<=n;l++){
			for(;sum[r]-sum[l-1]+m>=1ll*a[r]*(r-l+1) and r<=n;r++)ans=max(ans,r-l+1);
			//printf("<%lld %lld>,",r,l);
			//printf("%lld ",r-l);
		} 
		printf("%lld\n",ans);
	}
}
int main(){
	file();
	input();
	subsolve::func();
	return 0; 
}

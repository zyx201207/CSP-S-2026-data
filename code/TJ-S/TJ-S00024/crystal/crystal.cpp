#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ull unsigned long long
LL n;
ull m;
LL a[500010];
LL ans=0; 
LL f(LL x){
	LL cnt=0;
	ull sum=0;
	for(LL i=x-1;i>=1;i--){
		if(sum+(ull)(a[x]-a[i])>m){
			break;
		}else{
			sum+=(ull)(a[x]-a[i]);
			cnt++;
		}
	}
	return cnt+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%lld%llu",&n,&m);
	for(LL i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(LL i=n;i>1;i--){
		ans=max(ans,f(i));
	}
	printf("%lld",ans);
	return 0;
}

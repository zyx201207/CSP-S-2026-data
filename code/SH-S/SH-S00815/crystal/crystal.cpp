#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,a[maxn],m,ans;
long long sff[maxn];
bool check(long long x,long long y){
	if(sff[x]-sff[y+1]-(y-x+1)*(a[n]-a[y])>m){
		return false;
	}else{
		return true;
	}
}
long long calc_ans(long long o1,long long o2,long long now){
	if(o1==o2){
		return o1;
	}
	long long mid=(o1+o2)/2;
	if(!check(mid,now)){
		return calc_ans(mid+1,o2,now);
	}else{
		return calc_ans(o1,mid,now);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		sff[i]=sff[i+1]+(a[n]-a[i]);
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,i-calc_ans(1,i,i)+1);
	}
	printf("%lld",ans);
	return 0;
}
//Oct31==Dec25?

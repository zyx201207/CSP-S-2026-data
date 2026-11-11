#include<bits/stdc++.h>
typedef long long ll;
const int N=5e5+10;
ll a[N],m;int n;
bool check(int x){
	ll sum=0;
	for(int i=1;i<=x;i++) sum+=a[x]-a[i];
//	printf("%d %d %lld\n",1,x,sum);
	if(sum<=m) return true;
	for(int i=x+1;i<=n;i++){
		sum-=(a[i-1]-a[i-x]);
		sum+=(x-1)*(a[i]-a[i-1]);
//		printf("%d %d %lld\n",i-x,i,sum);
		if(sum<=m) return true;
	}
	return false;
}
int main(){
	std::freopen("crystal.in","r",stdin);
	std::freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d",l);
	return 0;
}
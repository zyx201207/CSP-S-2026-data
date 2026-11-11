#include<bits/stdc++.h>
using namespace std;
int n,l,r,ans;
long long m,x,cnt,a[500005],sum[500005];
bool fa,fb;
bool check(int k){
	for(int i=k;i<=n;i++){
		if(a[i]*k-sum[i]+sum[i-k]<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	fa=1,fb=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i) fa=0;
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) fb=0; 
	}
	if(fa==1){
		for(int i=n;i>=1;i--){
			x=(long long)i*(i-1)/2;
			if(x<=m){
				printf("%d",i);
				break;
			}
		}
		return 0;
	}
	if(fb==1){
		x=a[2]-a[1];
		for(int i=n;i>=1;i--){
			cnt=x*(long long)i*(i-1)/2;
			if(cnt<=m){
				printf("%d",i);
				break;
			}
		}
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid;
	}
	printf("%d",ans);
	return 0;
}
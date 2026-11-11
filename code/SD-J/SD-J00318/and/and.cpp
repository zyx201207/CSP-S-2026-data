#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200007],k,ans,mx=-4355;
long long f(long long x,long long y){
	long long n=max(x,y),ans=0,i=1;
	while(n!=0){
		if(x%2==1 && y%2==1){
			ans+=i;
		}
		x/=2;
		y/=2;
		i*=2;
		n/=2;
	}
	return ans;
}
bool cmp(long long a,long long b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mx=max(mx,a[i]);
	}
	sort(a+1,a+1+n,cmp);
	if(k==1){
		cout<<a[1];
	}else{
		if(k==2){
			long long mx=-342432;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					mx=max(mx,f(a[i],a[j]));
				}
			}
			printf("%lld",mx);
		}else{
			if(k==n){
				long long ans=a[1];
				for(int i=2;i<=n;i++){
					ans=f(ans,a[i]);
				}
			}else{
				long long ans2=a[1];
				for(int i=1;i<=k;i++){
					ans2=f(ans2,a[i]);
				}
				printf("%lld",ans2);
			}
		}
	}
	return 0;
}

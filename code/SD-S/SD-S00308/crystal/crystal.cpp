#include<bits/stdc++.h>
#define N 500005
#define ll long long
using namespace std;
int n;
ll m;
ll a[N];
ll sum[N];
ll ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	ll mx=0;
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
//		cout<<sum[i]<<' ';
	}
//	cout<<endl;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
	}
//	cout<<sum[3860]-a[1]*3860<<endl;
	ll l=1;
	for(int i=1;i<=n;++i){
		while(a[i]*(i-l+1)-(sum[i]-sum[l-1])>m)++l;
		ans=max(ans,i-l+1);
	} 
	printf("%lld",ans);
	return 0;
} 

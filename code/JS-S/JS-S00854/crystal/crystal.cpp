#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500009],sum[500009];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//~ freopen("crystal3.in","r",stdin);
	//~ freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
	}
	int maxn=0;
	for(int i=1;i<=n;++i){
		int l=0,r=i;
		while(l+1<r){
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m) r=mid;
			else l=mid;
		}
		//~ cout<<i<<' '<<r<<":"<<sum[i]-sum[r-1]<<' '<<(i-r)*a[i]-(sum[i]-sum[r-1])<<endl;
		maxn=max(maxn,i-r+1);
	}
	printf("%lld",maxn);
	return 0;
}

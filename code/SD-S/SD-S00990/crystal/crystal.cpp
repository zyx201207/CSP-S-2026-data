#include<bits/stdc++.h>
//#define int ll
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans;
ll m,a[N],sum[N];
ll get_sum(int l,int r){
	return l>1?sum[r]-sum[l-1]-1ll*(a[r]-a[l-1])*(l-1):sum[r];
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crydtal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+1ll*(a[i]-a[i-1])*(i-1);
	} 
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(get_sum(mid,i)<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
	return 0;
}

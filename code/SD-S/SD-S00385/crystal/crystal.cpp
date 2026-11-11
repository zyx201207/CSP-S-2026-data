#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define ll long long
int n; ll m;
ll a[N];
ll sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			ll tmp=sum[i]-sum[mid-1];
			if(1ll*(i-mid+1)*a[i]-tmp<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%d\n",ans);
	return 0;
}


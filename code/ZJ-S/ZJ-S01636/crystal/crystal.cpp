#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define sca scanf
#define pri printf
using namespace std;
const int N=5e5+100;
ll n,m,ans=-1;
ll a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	sca("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)sca("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=2;i<=n;i++){
		if(a[i]==a[i+1])continue;
		ll l=1,r=i-1,mid,ad;
		while(l<r){
			mid=(l+r)>>1;
			ad=a[i]*(i-mid+1)-(sum[i]-sum[mid-1]);
//			pri(" l=%d,r=%d,mid=%d,op=%lld\n",l,r,mid,ad);
			if(ad<=m){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	pri("%lld",ans);
	return 0;
}
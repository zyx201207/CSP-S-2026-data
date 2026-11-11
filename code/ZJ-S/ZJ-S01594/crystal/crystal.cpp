#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N],n,m,ans;
ll qian[N];
bool check(ll x,ll i){
	return(i-x+1)*a[i]-qian[i]+qian[x-1]<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		qian[i]=qian[i-1]+a[i];
	for(ll i=1;i<=n;i++){;
		ll l=1,r=i,ans2=1;
		while(l<=r){
			ll mid=l+(r-l)/2;
			if(check(mid,i)){
				ans2=mid,r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,i-ans2+1);
	}
	printf("%lld",ans);
	return 0;
}

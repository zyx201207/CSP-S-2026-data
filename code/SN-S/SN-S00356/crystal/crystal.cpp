// 管晨清 陕西省西安爱知中学 SN-S00356 
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll N=5e5+10;
ll n,m;
ll a[N],pre[N],ret=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;++i) pre[i]=pre[i-1]+a[i];
	for(ll i=1;i<=n;++i){
		ll l=1,r=i,ans=i;
		while(l<=r){
			ll mid=(l+r)>>1;
			//cout<<i<<' '<<mid<<' '<<(i-mid)*(a[i])-pre[i-1]-pre[mid-1]<<' '<<a[i]<<' '<<pre[i]<<endl;
			if((i-mid)*(a[i])-pre[i-1]+pre[mid-1]<=m) {
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		//cout<<ans<<endl;
		ret=max(ret,i-ans+1);
	}
	cout<<ret;
} 

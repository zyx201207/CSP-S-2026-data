#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid (((ll)l+r)>>1)
ll n,m,a[500005],h[500005],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		h[i]=h[i-1]+a[i];
	}
	for(ll i=2;i<=n;i++){
		ll l=1,r=i,t=i;
		while(l<=r){
//			cout<<l<<' '<<r<<' '<<mid<<' '<<(a[i]*(i-mid+1))<<' '<<(h[i]-h[mid-1])<<'\n';
			if((a[i]*(i-mid+1))-(h[i]-h[mid-1])<=m){
				t=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
//		cout<<'\n';
		ans=max(ans,i-t+1);
	}
	cout<<ans;
	return 0;
}

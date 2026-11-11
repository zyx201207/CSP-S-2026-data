#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,a[N],m,b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		b[i]=a[i];
		b[i]+=b[i-1];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll l=1;
		ll r=i-1;
		while(l<=r){
			ll mid=(l+r)/2;
			ll kk=(i-mid)*a[i];
			if(m>=kk-b[i-1]+b[mid-1]){
				r=mid-1;
			}
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}

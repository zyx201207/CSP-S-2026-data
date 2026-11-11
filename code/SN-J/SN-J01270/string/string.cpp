//brown or yellow question,and it runs for O(n log n), costs memory less than 5MB
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,sn;
ll a[200005],sa[200005];
char c[200005];
ll l,r;
ll ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sn+=a[i];
	}
	ll pos=0;
	ll p=(sn+1)/2;
	for(ll i=1;i<=n;i++){
		if(p<=a[i]){
			pos=i;
			break;
		}
		p-=a[i];
	}
	for(ll i=1;i<=n;i++) sa[i]=sa[i-1]+a[i];
	sn=sa[n];
	l=1,r=n;
	ll mid=(sn+1)/2;
	if(sn%2==1) l=r=mid;
	else l=mid,r=mid+1;
	while(l>1&&r<sn){
		ll pl=lower_bound(sa+1,sa+n+1,l)-sa-1;
		ll pr=upper_bound(sa+1,sa+n+1,r)-sa;
		if(l-sa[pl]<=sa[pr]+1-r){
			ll mo=l-sa[pl];
			l-=mo;
			r+=mo;
			if(c[pl+1]!=c[pr]) ans+=mo;
		}
		else{
			ll mo=sa[pr]+1-r;
			l-=mo;
			r+=mo;
			if(c[pl+1]!=c[pr]) ans+=mo;
		}
	}
	cout<<ans;
	return 0;
}

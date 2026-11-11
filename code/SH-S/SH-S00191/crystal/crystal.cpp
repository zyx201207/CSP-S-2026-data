#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500009;
ll n,m,a[N],s[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(ll i=1;i<=n;i++){
		ll l=1,r=i,tmp=0;
		while(l<=r){
			ll mid=(l+r)/2;
			if(a[i]*mid-s[i]+s[i-mid]<=m) tmp=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,tmp);
	}
	cout<<ans<<'\n';
	return 0;
} 

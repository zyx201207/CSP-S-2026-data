#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll biao=1e6+10;
ll a[biao],s[biao],n,m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll l=0,r=i;
		while(l+1<r){
			ll mid=l+r>>1;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;typedef unsigned long long ull;
const int N=5e5+1156;
ll a[N];
ll c[N];
ll s[N];
ll n,m;
//ll val(int st,int k){
//	ll ans=0;
//	for(int i=st;i<=k;i++){
//		ans+=a[k]-a[i];
//	}
//	return ans;
//}
ll val(ll l,ll r){
	return a[r]*(r-l+1)-(s[r]-s[l-1]);
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n-1;i++){
		c[i]=a[i+1]-a[i];
		s[i]=s[i-1]+a[i];
//		cout<<c[i]<<" ";
	}
	ll ans=0;
	for(ll k=1;k<=n;k++){
		//k 目标
		ll l=1,r=k,mid;
		while(l<=r){
			mid=(l+r)>>1;
			if(val(mid,k)<=m){
				ans=max(ans,k-mid+1);
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
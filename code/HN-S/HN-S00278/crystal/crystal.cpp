#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[500010],s[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]+s[i-1]; 
	}
	sort(a+1,a+n+1);
	for(ll i=n;i>=1;i--){
		ll l=1,r=i;
		while(l<r){
			ll mid=(r-l)/2+l,k=i-mid;
			if((k*a[i]-(s[i-1]-s[i-k-1]))<=m){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);cout<<i<<' '<<ans<<endl;
	}
	cout<<ans;
	return 0;
}

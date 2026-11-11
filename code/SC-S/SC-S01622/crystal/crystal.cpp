#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],s[N],ans;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)s[i]=a[n]-a[i],s[i]+=s[i-1];
	for(ll i=1;i<=n;i++){
		ll cnt=0,j=i,l=1,r=i;
		while(l<=r){
			ll mid=(l+r)/2;
			if((s[i]-s[mid-1]-(i-mid+1)*(a[n]-a[i]))>m){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,i-r);
	}
	cout<<ans;
}

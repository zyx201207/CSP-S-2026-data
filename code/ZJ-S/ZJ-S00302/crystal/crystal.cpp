#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const int N=1e6+10,M=1e3+10,MOD=1e9+7;
ll n,m,a[N],s[N],ans=0;
bool cmp(ll q,ll h){
	return q>h;
}
int main(){
	fastio;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(ll i=2;i<=n;i++) a[i]=a[1]-a[i];
	a[1]=0;
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(ll i=1;i<=n;i++){
		ll l=i,r=n,res=i;
		while(l<=r){
			ll mid=(l+r)/2;
			ll len=mid-i+1;
			ll cnt=s[mid]-s[i-1]-len*a[i];
			if(cnt>m) r=mid-1;
			else{
				l=mid+1;
				res=mid;
			}
		}
		ans=max(ans,res-i+1);
	}
	cout<<ans;
	return 0;
}

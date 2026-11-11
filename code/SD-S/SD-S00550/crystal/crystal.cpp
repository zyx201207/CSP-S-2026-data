#include<bits/stdc++.h>
#define mid ((l+r)>>1)
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,ans=0;
ll a[N],s[N];
bool check(ll l,ll r){
	ll numop=a[r]*(r-l+1)-(s[r]-s[l-1]);
	return numop<=m;
}
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++) s[i]=a[i]+s[i-1];
	for(ll i=1;i<=n;i++){
		ll l=1,r=i;
		while(l<r){
			if(check(mid,i)) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}


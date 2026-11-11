#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll> 
using namespace std;
const ll N=5e5+10;
ll n,m,ans,a[N],s[N];
bool check(ll l,ll r){
	return max(a[l],a[r])*(r-l+1)-(s[r]-s[l-1])<=m;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(ll l=1,r=1;l<=n;l++){
		while(l<=r&&r<n&&check(l,r+1))r++;
		//cout<<l<<' '<<r<<' '<<check(l,r)<<"\n";
		if(l<=r)ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}

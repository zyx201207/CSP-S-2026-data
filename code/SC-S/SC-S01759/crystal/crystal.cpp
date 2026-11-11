#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[510000],s[510000];
ll solve(ll x){
	if(x==1)return 0;
	ll d=a[x];
	ll l=1,r=x-1,mid,ans=-1;
	while(l<=r){
		mid=(l+r)>>1;
		ll sum=s[x-1]-s[mid-1];
		if((x-mid)*d-sum<=m){
			r=mid-1;
			ans=x-mid;
		}else l=mid+1;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,solve(i)+1);
	}
	cout<<ans;
	return 0;
}//rp++ rp++ rp++ rp++ rp++
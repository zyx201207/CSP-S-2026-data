#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500010];
ll s[500010];
bool check(ll x){
	ll sum=LLONG_MAX;
	for(int i=1;i<n-x+2;i++){
		ll p=x*a[i+x-1]-(s[i+x-1]-s[i-1]);
		sum=min(sum,p);
	}
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	ll l=0,r=n,ans=-1;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

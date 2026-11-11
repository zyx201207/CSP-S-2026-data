#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;
ll a[500010],s[500010];
ll aaa[500010];
ll ans,sum,cnt;
ll fd(int x){
	ll l=0,r=x-1;
	ll sum;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(mid*a[x]-s[x-1]+s[x-mid-1]<=m){
			l=mid+1;
			sum=mid;
		}else{
			r=mid-1;
		}
	}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	for(int i=1;i<=n;i++){
		ans=max(fd(i)+1,ans);
	}
	cout<<ans;
	return 0;
}

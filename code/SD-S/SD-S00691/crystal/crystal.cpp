#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],sum[N],ans,s;
bool check(ll mid,ll t){
	ll k=s-(t*(mid-1)-sum[mid-1]);
	if(m>=k) return 1;
	return 0;
}
ll erfen(ll l,ll r,ll t){
	while(l<r){
		ll mid=(l+r)/2;
		if(check(mid,t)){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		s=a[i]*i-sum[i];
		ans=max(ans,i-erfen(1,i,a[i])+1);
	}
	cout<<ans;
	return 0;
}

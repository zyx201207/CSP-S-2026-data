#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005],sum[500005];
bool check(ll num){
	ll res=9e18;
	for(ll l=1;l+num-1<=n;l++){
		int r=l+num-1;
		res=min(res,a[r]*num-(sum[r]-sum[l-1]));
	}
	return res>m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	ll mx;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mx=max(mx,a[i]);
	}
	int summ=0;
	for(int i=1;i<=n;i++){
		summ+=mx-a[i];
	}
	if(summ<=m){
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	if(m==0){
		int ans=0;
		for(int i=1;i<=n;i++){
			int res=1;
			while(a[i]==a[i+1]){
				i++;
				res++;
			}
			ans=max(ans,res);
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			int res=1;
			while(a[i]==a[i+1]){
				i++;
				res++;
			}
			ans=max(ans,res);
		}
		for(int i=1;i<=n-1;i++){
			int res=0;
			if(a[i]+1==a[i+1]){
				res++;
			}
			ans=max(ans,res);
		}
		cout<<ans;
		return 0;
	}
	int l=1,r=1e9;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
		}else{
			l=mid;
		}
	}
	cout<<l;
	return 0;
}

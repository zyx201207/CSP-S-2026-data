#include<bits/stdc++.h>
using namespace  std;
int n;
#define ll long long
ll a[500005];
ll m;
ll arr[500005];
ll ans;
bool check(ll i,ll x){
	if(a[i]*(i-x)-(arr[i-1]-arr[x-1])<=m){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		arr[i]=arr[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ll l=1,r=i-1;
		while(l<r){
			ll mid=(l+r)/2;
			if(check(i,mid)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans; 
	return 0;
}

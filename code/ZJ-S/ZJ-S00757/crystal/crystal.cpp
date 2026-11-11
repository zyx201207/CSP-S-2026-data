#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll  sum[500007],a[500007];
bool check(ll x){
//	cout<<x<<'\n';
	ll flag=0;
	for(ll i=1;i<=n-x+1;i++){
		if(a[i+x-1]*x-sum[i+x-1]+sum[i-1]<=m)flag=1;
//		cout<<a[i+x-1]*x<<' '<<sum[i+x-1]<<' '<<sum[i-1]<<'\n';
	}
	return flag;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll L=1,R=n;
	while(L<=R){
		ll mid=L+R>>1;
		if(check(mid))L=mid+1;
		else R=mid-1;
	}
	cout<<R;
	return 0;
}

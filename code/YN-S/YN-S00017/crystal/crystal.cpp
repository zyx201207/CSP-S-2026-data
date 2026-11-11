#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+20;
ll a[N];
ll sum[N]; 
ll ef(int pos,ll dm){
	ll dis=0;
	for(ll i=23;i>=0;i--){
		ll tmp=dis+(1<<i);
		if(tmp>pos)continue;
		if(a[pos]*tmp-(sum[pos]-sum[pos-tmp])<=dm){
		//	cout<<dm<<" "<<a[pos]*tmp-(sum[pos]-sum[pos-dis])<<"]]]";
			dis=tmp;
		}
	}
	return dis;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	//cout<<a[1]<<" "<<a[2]<<" "<<a[3];
	ll ans=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,ef(i,m));	
	}
	cout<<ans;
	return 0;
}

/*
5 8
-3 -1 2 2 7
*/
#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll n,m,ans;
ll a[N];
void dfs(ll i,ll ans1,ll m1){
	if(i==n){
		if(m1==m-1)ans=max(ans,ans1&a[i]);
		if(m1==m)ans=max(ans,ans1);
		return;
	}
	if(m1<m){
		dfs(i+1,ans1&a[i+1],m1+1);
	}
	dfs(i+1,ans1,m1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(ll i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;return 0;
	}
	if(m==n){
		ans=a[1];
		for(ll i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;return 0;
	}
	if(m==2){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++) ans=max(ans,(a[i]&a[j]));
		}
		cout<<ans;
		return 0;
	}
	if(n<=20){
		ll u=1;
		for(int i=1;i<=30;i++) u*=2;
		u--;
		dfs(0,u,0);
		cout<<ans;
		return 0;
	}
	return 0;
}

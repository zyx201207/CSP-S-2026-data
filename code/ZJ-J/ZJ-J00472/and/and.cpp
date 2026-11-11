#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll n,m,a[N],ans=0,vis[N],k[N];
void dfs(ll x,ll sum,ll cnt){
	if(x>n) return;
	if(sum==m){
		ans=max(ans,cnt);
		return;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(i,sum+1,(cnt & a[i]));
		vis[i]=0;
	}
}
bool check(){
	bool f=0;
	for(ll i=0;i<=20;i++){
		if(n==k[i]) f=1;
	}
	if(f==0) return 0;
	for(ll i=1;i<=n;i++){
		if(a[i]!=i-1) return 0;
	}
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(vis,0,sizeof vis);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		ans=a[1];
		for(ll i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(ll i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(n<=20){
		for(ll i=1;i<=n;i++){
			vis[i]=1;
			dfs(i,1,a[i]);
			vis[i]=0;
		}
		cout<<ans;
		return 0;
	}
	if(check()){
		ans=a[n];
		for(ll i=n-1;i>=n-m+1;i--){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	ans=a[n];
	for(ll i=n-1;i>=n-m+1;i--){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}

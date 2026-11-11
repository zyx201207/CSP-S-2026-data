#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200010],b[200010],dp[30];
int dfs(int x,int y){
	if(x==1){
		ll ans=0;
		for(ll i=1;i<=y;i++) ans=max(ans,a[i]);
		return ans;
	}
	if(y==x){
		ll sum=a[1];
		for(int i=2;i<=n;i++) sum&=a[i];
		return sum;
	}
	return max(dfs(x-1,y-1)&a[y],dfs(x,y-1));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(n==m){
		ll sum=a[1];
		for(ll i=2;i<=n;i++) sum&=a[i];
		cout<<sum;
	}else if(m==1){
		ll ans=0;
		for(ll i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
	}else if(m==2){
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans; 
	}else if(n<=20){
		cout<<dfs(m,n);
	}else if(m==n-1){
		ll sum=a[1],ans;
		for(ll i=2;i<=n;i++) sum&=a[i];
		for(ll i=1;i<=n;i++) ans=max(ans,sum^a[i]);
		cout<<ans;
	}else{
		ll sum=a[n];
		for(ll i=n-1;i>n-m;i++) sum&=a[i];
		cout<<ans;
	}
	return 0; 
}
//我是绝世骗骗花 
//巨难绿题 

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans=-10,m,a[200050];
void dfs(ll idx,ll cnt,ll sum){
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	if(sum<ans || n-idx+1<m-cnt) return;
	for(ll i=idx;i<=n;i++){
		dfs(i+1,cnt+1,sum&a[i]);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	ll t=pow(2,31)-1;
	dfs(1,0,t);
	cout<<ans;
	return 0;
}

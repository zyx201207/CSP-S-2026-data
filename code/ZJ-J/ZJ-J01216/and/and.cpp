#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll n,m;
ll a[N];
ll vis[N];
ll maxn;
void dfs(ll l,ll cnt,ll ans){
	if(cnt==m){
		maxn=max(maxn,ans);
		return ;
	}
	if(l==n+1) return ;
	if(!vis[l]){
		vis[l]=1;
		dfs(l+1,cnt+1,ans&a[l]);
		vis[l]=0;
	}
	dfs(l+1,cnt,ans);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,0,(ll)2e18-1);
	cout<<maxn;
	return 0;
}
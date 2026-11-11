#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
ll a[200010];
ll ma=-2e9,mx=-2e9;
void dfs(ll lvl,ll cnt,ll sum){
	if(lvl==n+1){
		if(cnt==m){
			ma=max(ma,sum);
		}
		return ;
	}
	if(cnt>m) return ;
	ll x=sum&a[lvl];
	dfs(lvl+1,cnt+1,x);
	dfs(lvl+1,cnt,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	dfs(1,0,mx);
	cout<<ma;
	return 0;
}
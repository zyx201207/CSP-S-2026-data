#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N],n,u=1,ans,m;
void dfs(ll x,ll e,ll cnt){
	if(x!=0&&cnt==m)ans=max(ans,e);
	if(x==n+1||cnt==m)return;
	for(int i=x+1;i<=n;i++){
		dfs(i,e&a[i],cnt+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=31;i++){
		u=u*2+1;
	}
	dfs(0,u,0);
	cout<<ans;
	return 0;
}
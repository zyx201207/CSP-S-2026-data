#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],n,m,ans;
void dfs(ll now,ll num){
	if(now==m){
		ans=max(ans,num);
		return ;
	}
	for(int i=1+now;i<=n;i++){
		dfs(now+1,num&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		dfs(1,a[i]);
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200086],n,m,ans;
void dfs(int x,int t,int s){
	if(t==m){
		ans=max(ans,s);
		return;
	}
	if(t+n-x<m||t>m)return;
	if(t==0)dfs(x+1,t+1,a[x]);
	else dfs(x+1,t+1,s&a[x]);
	dfs(x+1,t,s);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

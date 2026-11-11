#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
bool vis[200005];
int n,m;
int ans=-1;
void dfs(int p,int s){
	if(s>=m){
		ans=max(ans,p);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])return;
		vis[i]=true;
		if(p!=-1)dfs(p&a[i],s+1);
		else dfs(a[i],s+1);
		vis[i]=false;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(-1,0);
	cout<<ans;
	return 0;
} 

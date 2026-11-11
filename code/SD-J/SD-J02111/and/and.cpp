#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1000000000;
int a[200005],vis[200005];
void dfs(int now,int cnt){
	if(cnt==m){
		ans=max(ans,now);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(now&a[i],cnt+1);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(a[i],1);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}

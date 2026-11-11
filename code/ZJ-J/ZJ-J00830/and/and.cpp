#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[200005],vis[200005];
void dfs(int p,long long l,int jishu){
	if(jishu==m){
		ans=max(ans,l);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			long long k=l&a[i];
			dfs(i,k,jishu+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		vis[i]=1;
		dfs(i,a[i],1);
	}
	cout<<ans;
	return 0;
}

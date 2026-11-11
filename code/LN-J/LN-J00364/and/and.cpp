#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],vis[200005],mx=0;
void dfs(int nm,int depth,int ans){
	if(depth==m){
		ans&=nm;
		mx=max(mx,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(a[i],depth+1,ans&nm);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(a[i],1,a[i]);
		memset(vis,0,sizeof vis);
	}
	cout<<mx;
    return 0;
}
//qp兜售小main包烤绿鸟

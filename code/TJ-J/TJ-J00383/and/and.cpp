#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans[200005];
int vis[200005];
int maxn=-1;
void dfs(int dep){
	if(dep==m+1){
		int t=ans[1];
		for(int i=2;i<=m;i++){
			t&=ans[i];
		}
		maxn=max(maxn,t);
		return ;
	}
	for(int i=dep;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			ans[dep]=a[i];
			dfs(dep+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//cin>>n>>m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		//cin>>a[i];
		scanf("%d",&a[i]);
	}
	dfs(1);
	printf("%d",maxn);
	return 0;
}

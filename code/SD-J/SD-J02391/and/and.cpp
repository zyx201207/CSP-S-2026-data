#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],vis[1000010],ans=0;
void dfs(int s,int ma){
	if(s==m+1){
		ans=max(ans,ma);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(s==1)ma=a[i];
			dfs(s+1,ma&a[i]);
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
	dfs(1,0);
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2005],vis[2005],ans=0;
void dfs(int dep,int num){
	if(dep==m+1){
		ans=max(ans,num);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]==1){
			vis[i]=1;
			dfs(dep+1,num&a[i]);
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
	dfs(1,pow(2,30)-1);
	cout<<ans;
	return 0;
}

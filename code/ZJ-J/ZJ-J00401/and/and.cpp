#include<bits/stdc++.h>
using namespace std;
int  n,m,a[10000],vis[10000];
int x=(2<<30)-1,ans=-1;
void dfs(int o,int p){
	if(o==0){
		ans=max(ans,p);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(o-1,p&a[i]);
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
	dfs(m,x);
	cout<<ans;
}
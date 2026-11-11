#include<bits/stdc++.h>
using namespace std;
int a[200001],f[200001],ans=-1,n,m;
void dfs(int k,int v,int l){
	if(l==m){
		ans=max(ans,v);
		return;
	}for(int i=k+1;i<=n;i++){
		dfs(i,v&a[i],l+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<=n-m;i++)dfs(i,a[i],1);
	cout<<ans;
}

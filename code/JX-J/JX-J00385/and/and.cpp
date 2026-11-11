#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
void dfs(int w,int s,int z){
	if(s==m){
		ans=max(ans,z);
		return ;
	}
	for(int i=w+1;i<=n;i++){
		if(a[i]==0) continue;
		dfs(i,s+1,z&a[i]);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m;i++){
		if(a[i]==0) continue;
		dfs(i,1,a[i]);
	}
	cout<<ans;
	return 0;
}

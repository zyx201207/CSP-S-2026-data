#include<bits/stdc++.h> 
using namespace std;
int n,m,a[2005],ans=0;
void dfs(int i,int j,int k,int s){
	if(i==1){
		if(s==0) s=a[j];
		else s=s&a[j];
	} 
	if(k==m){
		ans=max(s,ans);
		return ;	
	}
	dfs(0,j+1,k,s);
	dfs(1,j+1,k++,s);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}

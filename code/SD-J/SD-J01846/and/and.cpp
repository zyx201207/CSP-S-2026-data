#include<bits/stdc++.h>
using namespace std;
int n,m,maxx=0,vis[20010];
int a[200010],b[200010];
void dfs(int i,int step){
	 if(i==n+1){
	 	int ans=b[1];
	 	for(int i=2;i<=n;i++){
	 		ans&=b[i];
		}
		maxx=max(maxx,ans);
		return;
	 }
	 for(int i=1;i<=n;i++){
	 	if(!vis[i]){
	 		b[step]=a[i];
	 		vis[i]=1;
	 		dfs(i+1,step+1);
	 		vis[i]=0;
		 }
	 }
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,1);
	cout<<maxx;
}

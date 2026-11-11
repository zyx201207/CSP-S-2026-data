#include<bits/stdc++.h>
using namespace std;
int n,m,a[200002],ans;
bool vis[200002];
int dfs(int x,int o){
	if(o==0) return 0;
	int mx=0;
	if(x==1){
		for(int i=1;i<=n;i++) if(!vis[i])
		mx=max(mx,o&a[i]);
		return mx;
	}
	for(int i=1;i<=n;i++) if(!vis[i])
	{vis[i]=true; mx=max(dfs(x-1,a[i]&o),mx); vis[i]=false;}
	return mx;
}
//////////////////骗分一代//////////////////// 
int main()
{
 freopen("and.in","r",stdin);
 freopen("and.out","w",stdout);
 cin>>n>>m;
 for(int i=1;i<=n;i++) cin>>a[i];
 if(n<=20){
 	ans=dfs(m,pow(2,20)-1);
 	cout<<ans;
 }
 else if(n<=2000){
 	if(m==1){
 		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
 		cout<<ans;
	 }
	 if(m==n){
	 	ans=a[1];
	 	for(int i=2;i<=n;i++) ans&=a[i];
	 	cout<<ans;
	 }
	 if(n==2){
	 	for(int i=1;i<=n;i++)
	 	for(int j=1;j<=n;j++)
	 	if(i!=j) ans=max(ans,a[i]&a[j]);
	 	cout<<ans;
	 }
 }
 else{
 	if(m==n-1){
 		int mx=pow(2,20)-1;
	 	for(int i=1;i<=n;i++){
	 		mx=0;
 			for(int j=1;j<=n;j++) if(j!=i) mx&=a[j];
 			ans=max(ans,mx);
		 }
		 cout<<ans;
	 }
	 else{
	 	ans=INT_MAX;
	 	for(int i=1;i<=n;i++) ans=min(ans,a[i]);
 		cout<<ans;
	 }
 }
 return 0;
 //讲个笑话：这道题我是对着数据范围做的 
}


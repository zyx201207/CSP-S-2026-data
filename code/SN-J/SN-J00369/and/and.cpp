#include<bits/stdc++.h>
using namespace std;
int n,m,a[20000],ans=-1,vis[20000],mm[20000];
void dfs(int id,int s){
	vis[id]=1,mm[s]=a[id]; 
	if(s==m){
		int x=mm[1];
		if(m==1){
			ans=max(ans,x);
		}else{
			for(int i=2;i<=m;i++){
				x=x&mm[i];
			}
			ans=max(ans,x);
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&s<=m){
			dfs(i,s+1);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
	}else if(m==n){
		int x=a[1];
		if(m==1){
			ans=max(ans,x);
		}else{
			for(int i=2;i<=m;i++){
				x=x&a[i];
			}
			ans=max(ans,x);
		}
	}else if(n>2000){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}else{
		dfs(0,0);
	}
	cout<<ans;
	return 0;
}
//4 2
//3 15 12 12

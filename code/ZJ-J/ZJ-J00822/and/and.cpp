#include <bits/stdc++.h>
using namespace std;
const long long inf=200005;
int ans=0;
int n,m;
int a[inf];
int vis[inf];
void dfs(int x,int step){
	if(step==0){
		if(ans<x){
			ans=x;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			int y=a[i]&x;
			dfs(y,step-1);
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
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(a[i],m-1);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[100005];
void dfs(int u,int sum,int nans){
	if (u==n+1&&sum==m){
		ans=max(ans,nans);
		return;
	}
	dfs(u+1,sum+1,nans&a[u]);
	dfs(u+1,sum,nans);
}
int main(){
	freopen("and.in","r+",stdin);
	freopen("and.out","w+",stdout);
	cin>>n>>m;
	if (n>20){
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}
	else{
		dfs(1,0,2147483647);
		cout<<ans;
	}
} 

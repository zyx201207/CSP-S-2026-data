#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[200005],ans=0;
void dfs(int x,int k,int sum){
	if(x==n+1){
		if(k==m){
			ans=max(ans,sum);
			return;
		} 
		else return;
	}
	dfs(x+1,k,sum);
	if(sum==0) dfs(x+1,k+1,a[x]);
	else{
		int res=(sum&a[x]);
		dfs(x+1,k+1,res);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

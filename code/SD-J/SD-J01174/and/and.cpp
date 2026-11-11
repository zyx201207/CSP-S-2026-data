#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200005];
int dp[200005];
int ans=0;

int dfs(int id,int h){
	if(h<0) return 0;
	ans=max(ans,dfs(id+1,h-1));
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,m);
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[200005],vis[200005];
int dp[200001][200000];
int dfs(int ai,int mi){
	if(dp[ai][mi])return dp[ai][mi];
	int sum=0;
	if(mi==m){
		//cout<<sum<<endl;
		return a[ai];
	}
	for(int i=ai+1;i<=n;i++){
		sum=max(sum,(a[ai]&dfs(i,mi+1)));
	}
	//cout<<ai<<' '<<mi<<':';cout<<sum<<"   ";
	//if(mi==1)cout<<endl;
	dp[ai][mi]=sum;
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n-m+1;i++){
		//cout<<dfs(i,1)<<' ';
		x=max(x,dfs(i,1));
	} 
	cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

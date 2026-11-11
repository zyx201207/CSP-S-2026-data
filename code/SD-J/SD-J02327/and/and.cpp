#include<bits/stdc++.h>
using namespace std; 
int n,m;
long long a[200005];
int dfs(int w,int s,int o){
	int ans=-1;
	ans=max(ans,dfs(w+1,s,o));
	if(s==-5) s=a[w];
	else s=s&a[w];
	ans=max(ans,dfs(w+1,s,o-1));
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(1,-5,m);
//	//for(int i=1;i<=m;i++) dp[i]=1ll<<30;
//	for(int i=1;i<=n;i++){
//		for(int j=m;j>=1;j--){
//			//if(dp[j]!=1ll<<30)
//			if(dp[j]==0) dp[j]=a[i];
//			dp[j]=max(dp[j],dp[j-1]&a[i]);
//			//else dp[j]=a[i];		
//		}
//	}
//	cout<<dp[m];
	
	return 0;
}

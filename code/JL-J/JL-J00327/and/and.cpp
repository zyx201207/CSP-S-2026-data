#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int dp[10005][10005];
int ans;
bool B=true;
void dfs(int select,int cnt,int sum){
	if(select>n){
		if(cnt==m) {ans=max(ans,sum);}

		return;
		
	}
	if(cnt<m){
		dfs(select+1,cnt+1,sum &  a[select]);
	}
	dfs(select+1,cnt,sum);
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	if(n==m){
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
		
	}
	if(n<=20){
		ans=0;
		
		dfs(1,0,-1);
		cout<<ans;
		return 0;
	}
	memset(dp,-1,sizeof dp);
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(i,m);j++){
			for(int k=j-1;k<=i-1;k++){
				dp[i][j]=max(dp[i][j],dp[k][j-1]&a[i]);
			}
			if(j==m){
				ans=max(ans,dp[i][j]);
			}	
		}
		
			
	}
	cout<<ans;
	return 0;
}/*
5 3
31 3 1 15 7*/

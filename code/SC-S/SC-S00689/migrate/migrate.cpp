#include<bits/stdc++.h>
using namespace std;
int a[2000100],dp[2000100],ans=0;
void dfs(int x,int n,int d){
	if(dp[x]){
		dp[x]++;
		return;
	}
	dp[x]++;
	for(int i=1;i<=d;i++){
		if(a[x]+d<a[x+i]){
			break;
		}
		dfs(x+i,n,d);
	}
}
int main(){
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		int n,d;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		} 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[j]=0;
			}
			dfs(i,n,d);
			for(int j=i+1;j<=n;j++){
				if(dp[j]==2) ans++;
			}
		}
	}
	return 0; 
}
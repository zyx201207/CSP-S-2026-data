#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b;
	cin>>a>>b;
	
	for(int doris=0;doris<b;doris++){
			int n,d;
		cin>>n>>d;
		int dp[50001]={};
		int vis[50001]={};
		for(int i=0;i<n;i++){
			cin>>dp[i];
			vis[dp[i]]=1;
		}
		int left=0;
		int right=n-1;
		int ans=0;
		while(left<right){
			if(dp[right]-dp[left]<=d){
				break;
			}else{
				if(vis[dp[left]+d-1]!=0 && vis[dp[right]-1]!=0){
					ans++;
				}
			} 
			left++;
		}cout<<ans;
	}
	
	 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int x[100001],dp[100001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
	
	int n,d;cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	int ans=0,tmp;
	for(int i=0;i<n;i++){
		memset(dp,0,sizeof(dp));
		for(int j=i+1;j<n;j++){
			int k=1;
			tmp=1;
			while(j-k>=i&&x[j]-x[j-k]<=d){
	
				if(dp[j]==0){
					dp[j]=dp[j-k]+1;k++;
					continue;
				}
				if(dp[j]==dp[j-k]+1){
					tmp++;k++;
					continue;
				}
				if(dp[j]>dp[j-k]+1){
					tmp=1;
					dp[j]=dp[j-k]+1;
					k++;
				}
			}
			if(tmp==2)ans++;
		}
		
	}
	cout<<ans<<endl;}
}

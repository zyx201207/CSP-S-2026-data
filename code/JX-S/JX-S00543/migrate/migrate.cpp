#include<bits/stdc++.h>
using namespace std;
int a[10005];
int dp[305];
int num[305];
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		memset(num,0,sizeof(num));
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		memset(dp,0x3f,sizeof(dp));
		int ans=0;
		for(int c=1;c<n;c++){
			memset(dp,0x3f,sizeof(dp));
			memset(num,0,sizeof(num));
			dp[c]=0;
			for(int i=c;i<n;i++){
				if(dp[i+1]==dp[i]+1){
					num[i+1]+=dp[i];
				}
				else if(dp[i+1]>dp[i]+1){
					dp[i+1]=dp[i]+1;
					num[i+1]=1;
				}
				for(int j=i+2;j<=n&&a[j]-a[i]<=m;j++){
					//cout<<dp[j]<<"\n";
					if(dp[j]==dp[i]+1){
						//cout<<"?";
						num[j]+=dp[i];
					}
					else if(dp[j]>dp[i]+1){
						//cout<<"good"<<"\n";
						dp[j]=dp[i]+1;
						num[j]=1;
					}
				}
				for(int i=c;i<=n;i++){
					if(num[i]==2)ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}

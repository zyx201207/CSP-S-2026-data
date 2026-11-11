#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,x[N],n,d,ans=0,num;
long long dp[5005][5005],step[5005][5005];//dp[i][j]表示从点i出发到点j的路径数 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		
		if(c==11 || c==12){
			if(d<x[2]-x[1]){
				cout<<0<<"\n";
				continue;
			}
			num=d/(x[2]-x[1]);
			if(num==1){
				cout<<0<<"\n";continue;
			}
			for(int i=1+2*num-1;i<=n;i++){
				ans++;
			}
			cout<<ans<<"\n";
			continue;
		}
		
		else{
			for(int i=1;i<=n;i++){
				dp[i][i]=1;
			}for(int j=1;j<=n;j++){
				for(int i=j;i>=1;i--){
					dp[i][j]=0;step[i][j]=0;
					if(x[j]-x[i]<=d){
						dp[i][j]=1;step[i][j]=1;
					}
					else{
						step[i][j]=1e9;
						for(int k=i+1;k<=j-1;k++){
							step[i][j]=min(step[i][j],step[i][k]+step[k][j]);
						}
						for(int k=i+1;k<=j-1;k++){
							if(step[i][j]==step[i][k]+step[k][j] && step[i][k]==1){
								dp[i][j]+=dp[i][k]*dp[k][j];
							}
						}
					}
					if(dp[i][j]==2)ans++;
				}
//				for(int i=1;i<=j;i++)cout<<dp[i][j]<<" ";
//				cout<<"\n";
			} 
			cout<<ans<<"\n";
		}
		
		
		
	}
	return 0;
} 

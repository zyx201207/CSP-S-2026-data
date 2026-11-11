#include<bits/stdc++.h>
using namespace std;
int c,t;
int x[2000005],dp[2005][2005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	dp[0][0]=dp[0][1]=0;
	while(t--){
		int n,d,sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int mi=1e9,ms=0;
				if(x[j]-x[i]<=d) ms=pow(2,j-i-1);
				else{
					for(int k=1;k<=d;k++){
						if(dp[i][j-k]+1==mi) ms++;
						else if(dp[i][j-k]+1<mi){
							ms=0;
							mi=dp[i][j-k];
						}
					}
				}
				if(ms==2) sum++;
			}
		}
		cout<<sum-1<<'\n';
		
	}
}
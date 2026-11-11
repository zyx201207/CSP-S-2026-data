#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		long long x[305];
		long long dp[305][305][305];
		for(int i=0;i<305;i++){
			for(int j=0;j<305;j++){
				for(int k=0;k<305;k++)dp[i][j][k]=0;
			}
		}
		for(int i=0;i<305;i++){
			dp[i][i][0]=1;
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=1;j<i;j++){
				if(x[i]-x[j]<=d){
					for(int k=1;k<=j;k++){
						for(int l=1;l<=300;l++){
							dp[k][i][l]+=dp[k][j][l-1];
						}
					}
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=1;k<=300;k++){
					if(dp[i][j][k]==0)continue;
					if(dp[i][j][k]==2){
						cnt++;
						break;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
}

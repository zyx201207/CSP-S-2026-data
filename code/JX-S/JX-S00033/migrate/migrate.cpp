#include<bits/stdc++.h>
using namespace std;

const int N=2e6+10;

//migrate answer

long long c,t,n,d;
long long x[N];
long long dp[5050][5050];

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dp[i][0]=1;
				for(int k=1;k<=j-i;k++){
					for(int l=i;l<=i+k;l++){
						if(x[i+k]-x[l]>=d){
							dp[i][k]=dp[i][k-1]+1;
						}
					}
					
				}
				if(dp[i][j]==2)cnt++;
			}
		}
		cout<<cnt<<"\n";

	}

	return 0;
}
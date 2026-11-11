//15 03
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+5;
int c,x[N],n,d;
struct sub1{
	const int N=300+5;
	int dp[N][N],f[N];
	int solve(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
					dp[i][j]=1;
				}
				else{
					dp[i][j]=1e9;
				}
			}
			dp[i][i]=0;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dp[i][k]+dp[k][j]>dp[i][j]){
						dp[i][k]+dp[k][j]=dp[i][j];
						
					}
				}
			}
		}
		
	}
};
int help(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n<=300){
		sub1 tmp;
		return tmp.solve();
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cout<<help()<<endl;
	} 
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int x[N];
int a[N][N],dp[N][N];
int c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			dp[i][i]=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				a[i][j]=x[j]-x[i];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[i][j]<=d) dp[i][j]=dp[i][j-1];
				else dp[i][j]=dp[i][j-1]+1;
				if(dp[i][j]==2) ans++;
			}
		}
		cout<<ans+1<<endl;
	}
	return 0;
} 

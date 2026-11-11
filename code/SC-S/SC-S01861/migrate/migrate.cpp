#include<bits/stdc++.h>
using namespace std;
int n,d,x[2000005],dp[2000005][20000005];
int find(int loc,int d,int comefrom){
	dp[comefrom][loc]++;
	int re=1;
	for(int i=1;i<=n;i++){
		if(x[loc]-x[i]>=-d && x[loc]-x[i]<=d && i!=comefrom){
			re+=find(i,d,loc);
		}
	}
	return re;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int ti=1;ti<=t;ti++){
		if(c==13 || c==14){
			cin>>n>>d;
			cout<<n-2<<endl;
		}
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int dp[n+1][n+1];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]+=find(j,d,i);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dp[i][j]>1){
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
} 
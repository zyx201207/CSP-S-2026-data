#include<bits/stdc++.h>
using namespace std;
#define mn(x,y) x=min(x,y)
int dp[1001][1001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,0x3f,sizeof dp);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;cin>>w;
		dp[i][i]=0;
		dp[i+n][i+n]=0;
		dp[i][i+n]=dp[i+n][i]=w;
	}
	int cnt=2*n;
	for(int i=1;i<=n;i++){
		int k;
		int a;
		cin>>k;
		for(int j=0;j<k;j++){
			int t;
			cin>>a>>t;
			cnt++;
			if(i!=0){
				mn(dp[cnt-1][cnt],0);
				mn(dp[cnt][cnt-1],0);
			}
			mn(dp[a+n][cnt],t);
			mn(dp[cnt][a+n],t);
			dp[cnt][cnt]=0;
		}
	}
	for(int k=1;k<=cnt;k++)
		for(int i=1;i<=cnt;i++)
			for(int j=1;j<=cnt;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

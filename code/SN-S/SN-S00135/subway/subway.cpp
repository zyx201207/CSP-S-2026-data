#include <bits/stdc++.h>
#define int long long 
using namespace std;
int c,n,m,d,q;
int w[405];
int k[505];
int a[205][405],t[205][405];
int dp[405][405];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j){
				dp[i][j]=0;
			}
			else{
				dp[i][j]=1e18;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int u=1;u<=k[i];u++){
			for(int v=u+1;v<=k[i];v++){
				dp[a[i][u]][a[i][v]]=min(dp[a[i][u]][a[i][v]],t[i][u]+t[i][v]);
				dp[a[i][v]][a[i][u]]=min(dp[a[i][v]][a[i][u]],t[i][u]+t[i][v]);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

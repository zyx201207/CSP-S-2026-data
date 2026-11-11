#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5;
int c,n,m,d,p,dp[N][N],k[N],w[N],a[N],t[N][N];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) dp[i][j]=INT_MAX;
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++) cin>>a[j]>>t[a[j]][i];//a is station
		for (int j=1;j<k[i];j++){
			for (int x=j+1;x<=k[i];x++){
				dp[a[j]][a[x]]=min(dp[a[j]][a[x]],t[a[j]][i]+t[a[x]][i]+w[a[j]]+w[a[x]]);
			}
		}											 
	}
	for (int len=2;len<=m;len++){
		for (int i=1;i+len-1<=m;i++){
			int j=i+len-1;
			for (int k=i;k<=j;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]-2*w[k]);
			}for (int k=j+1;k<=m;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[j][k]-2*w[k]);
			}for (int k=1;k<i;k++){
				dp[i][j]=min(dp[i][j],dp[k][j]+dp[k][i]-2*w[k]);
			}
		}
	}
	while (p--){
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]<<endl;
	}fclose(stdin);
	fclose(stdout);
}


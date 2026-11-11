#include<iostream>
#include<cstring>
using namespace std;
int c,n,m,d,q,w[20005],k[20005],a[505][20005],t[505][20005],x[20005],y[20005],ans,dp[20005][20005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		for(int j=1;j<=m;j++)dp[i][j]=200000004;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++){
			for(int p=j+1;p<=k[i];p++){
				dp[a[i][j]][a[i][p]]=t[i][j]+t[i][p];
				dp[a[i][p]][a[i][j]]=dp[a[i][j]][a[i][p]];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			for(int p=i;p<=j;p++){
				dp[i][j]=min(dp[i][j],dp[i][p]+dp[p][j]);
				dp[j][i]=dp[i][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		ans=dp[x[i]][y[i]]+w[x[i]]+w[y[i]];
		cout<<ans<<endl;
	}
	return 0;
}

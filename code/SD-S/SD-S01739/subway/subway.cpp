#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[505],dp[505][505],kk,x[505],v[505],r,l;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=1e17;
		}
		dp[i][i]=0;
	}
	for(int i=0;i<n;i++){
		cin>>kk;
		for(int j=0;j<kk;j++){
			cin>>x[j]>>v[j];
		}
		for(int ii=0;ii<=n;ii++){
			for(int jj=0;jj<=n;jj++){
				dp[x[ii]][x[jj]]=min(dp[x[ii]][x[jj]],v[ii]+v[jj]);
				dp[x[jj]][x[ii]]=min(dp[x[jj]][x[ii]],v[ii]+v[jj]);
			//cout<<x<<' '<< v+w<<' '<<y<<'\n';
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				dp[j][i]=min(dp[j][i],dp[j][k]+dp[k][i]);
			}
		}
	}
	while(q--){
		cin>>r>>l;
		cout<<dp[r][l]+a[r]+a[l]<<'\n';
	}
	return 0;
}


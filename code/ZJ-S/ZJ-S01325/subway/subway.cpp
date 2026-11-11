#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,a[500005],c,d,q,dp[505][505],k[505];
vector<int> v[500005],w[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++)dp[i][j]=1e18;
		for(int j=i+1;j<=n;j++)dp[i][j]=1e18;
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int aa,tt;
			cin>>aa>>tt;
			v[aa].push_back(i);
			w[aa].push_back(tt);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size()-1;j++){
			for(int l=j+1;l<v[i].size();l++){
				dp[v[i][j]][v[i][l]]=min(dp[v[i][j]][v[i][l]],w[i][j]+w[i][l]);
				dp[v[i][l]][v[i][j]]=min(dp[v[i][l]][v[i][j]],w[i][j]+w[i][l]);
			}
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][l]+dp[l][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int xx,yy,ans=1e18;
		cin>>xx>>yy;
		for(int j=0;j<v[xx].size();j++){
			for(int l=0;l<v[yy].size();l++){
				ans=min(ans,dp[v[xx][j]][v[yy][l]]+w[xx][j]+w[yy][l]);
			}
		}
		cout<<ans+a[xx]+a[yy]<<'\n';
	}
}


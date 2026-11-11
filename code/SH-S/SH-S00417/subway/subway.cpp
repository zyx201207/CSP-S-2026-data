#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500009];
int k[509];
vector<int> a[500009];
vector<int> t[500009];
int e[509][509];
int dp[509][509];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(i);
			t[u].push_back(v);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int l=0;l<a[i].size();l++){
			for(int r=0;r<a[i].size();r++){
				if(l!=r){
					//cout<<i<<endl;
					dp[a[i][l]][a[i][r]]=min(dp[a[i][l]][a[i][r]],t[i][l]+t[i][r]);
					dp[a[i][r]][a[i][l]]=min(dp[a[i][r]][a[i][l]],t[i][l]+t[i][r]);
					//cout<<a[i][l]<<" "<<a[i][r]<<" "<<dp[a[i][l]][a[i][r]]<<endl;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				dp[i][j]=min(dp[i][j],dp[i][l]+dp[l][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
//		}
//	}
	for(int i=1;i<=q;i++){
		int l,r;
		int ans=1e18;
		cin>>l>>r;
		for(int i=0;i<a[l].size();i++){
			for(int j=0;j<a[r].size();j++){
				ans=min(ans,dp[a[l][i]][a[r][j]]+t[l][i]+t[r][j]);
			}
		}
		cout<<ans+w[l]+w[r]<<"\n";
	}
	return 0;
}

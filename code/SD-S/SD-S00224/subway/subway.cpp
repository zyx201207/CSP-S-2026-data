#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[5005][5005];
int g[505][200005];
int t[505][200005];
int s[505];
int h[500005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	
	memset(dp,0x3f,sizeof(dp));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>h[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		s[i]=k;
		for(int j=1;j<=k;j++){
			int a,b;
			cin>>a>>b;
			g[i][j]=a;
			t[i][j]=b;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s[i];j++){
			for(int k=1;k<=s[i];k++){
				if(j==k) continue;
				dp[g[i][j]][g[i][k]]=t[i][j]+t[i][k];
				//cout<<j<<' '<<k<<' '<<dp[j][k]<<' '<<t[i][j]<<' '<<t[i][k]<<'\n';
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=min(i,j);k<=max(i,j);k++){
				//if(i==j) continue;
				dp[i][j]=min(dp[i][j],min(dp[i][k]+dp[k][j],dp[j][k]+dp[k][i]));
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			//cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<dp[u][v]+h[u]+h[v]<<'\n';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=2e4+9,M=2e4;
int w[N];
int k[509];
int y[509][N],t[509][N];
int dp[509][509];
int cnt[N];
bool fun(int r,int b){
	for(int i=1;i<=k[r];i++){
		if(y[r][i]==b) return 1;
	}
	return 0;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>y[i][j]>>t[i][y[i][j]];
			cnt[y[i][j]]=i;
		}
	}
	memset(dp,0x3f,sizeof dp);	
	for(int i=1;i<=n;i++) dp[i][i]=0;
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){
			if(a==b) continue;
			for(int c=1;c<=k[a];c++){
				for(int d=1;d<=k[b];d++){
					if(y[a][c]==y[b][d]){
						dp[a][b]=min(dp[a][b],t[a][y[a][c]]+t[b][y[a][c]]);
					}
				}
			}
		}
	}
	for(int c=1;c<=n;c++){
		for(int a=1;a<=n;a++){
			for(int b=1;b<=n;b++){
				dp[a][b]=min(dp[a][b],dp[a][c]+dp[c][b]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int xx,yy;
		cin>>xx>>yy;
		if(fun(cnt[xx],yy)) cnt[yy]=cnt[xx];
		else if(fun(cnt[yy],xx)) cnt[xx]=cnt[yy];
		cout<<dp[cnt[xx]][cnt[yy]]+w[xx]+w[yy]+t[cnt[xx]][xx]+t[cnt[yy]][yy]<<endl;
	}
	return 0;
}
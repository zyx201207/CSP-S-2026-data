#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=605,N=55;
int c,n,m,d,q,w[M],k[M],dp[M][M];
vector<int>v[N],ti[N];
struct node{
	int v,w;
};
vector<node>edge[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
		memset(dp,0x3f,sizeof(dp));
		for(int i=1;i<=m;i++)cin>>w[i];
		int tot=0;
		for(int i=1;i<=n;i++){
			cin>>k[i];
			vector<int>v2;
			for(int j=1,x,t;j<=k[i];j++){
				cin>>x>>t;
				tot++;
				v2.push_back(m+tot);
				v[x].push_back(m+tot);
				dp[x][m+tot]=dp[m+tot][x]=t;
			}
			for(auto x:v2)for(auto y:v2)dp[x][y]=0;
		}
		for(int i=1;i<=m+tot;i++)dp[i][i]=0;
		for(int l=1;l<=m+tot;l++){
			for(int i=1;i<=m+tot;i++){
				for(int j=1;j<=m+tot;j++){
					dp[i][j]=min(dp[i][j],dp[i][l]+dp[l][j]);
				}
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+dp[x][y]<<'\n';
		}
	return 0;
}

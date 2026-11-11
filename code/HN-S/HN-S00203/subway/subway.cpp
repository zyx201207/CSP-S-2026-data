#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;
int w[500005];
struct Node{
	int x,t;
};
int dp[505][505];
vector<Node>e[500005];
vector<Node>G[505];
bool cmp(Node x,Node y){
	return x.x<y.x;
} 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			e[a].push_back({i,t});
			G[i].push_back({a,t});
		}
		sort(G[i].begin(),G[i].end(),cmp);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			dp[i][j]=1e18; 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<G[i].size();j++){
			for(int k=i+1;k<=n;k++){
				int l=0,r=G[k].size();
				while(l+1<r){
					int mid=l+r>>1;
					if(G[k][mid].x<=G[i][j].x){
						l=mid;
					}else{
						r=mid;
					}
				}
				if(G[k][l].x==G[i][j].x){
					Node u=G[k][l];
					Node v=G[i][j]; 
					dp[i][k]=min(dp[i][k],u.t+v.t);
					dp[k][i]=min(dp[k][i],u.t+v.t);
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int minn=1e18;
		for(int i=0;i<e[x].size();i++){
			Node u=e[x][i];
			for(int j=0;j<e[y].size();j++){
				Node v=e[y][j];
				minn=min(minn,dp[u.x][v.x]+u.t+v.t+w[x]+w[y]);
			}
		} 
		cout<<minn<<endl;
	}
	return 0;
}

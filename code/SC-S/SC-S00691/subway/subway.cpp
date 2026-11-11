#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 505,M = 5e5+5,inf = 0x3f3f3f3f3f3f3f3f;
int w[M],n,m,f[N][N];
vector<pair<int,int>>g[M];
vector<pair<int,int>>adj[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			g[a].push_back({i,t});
			adj[i].push_back({a,t});
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		for(auto op:adj[i]){
			int a=op.first,t=op.second;
			for(auto k:g[a]){
				int j=k.first;
				f[i][j]=min(f[i][j],t+k.second);
			}
		}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
	while(q--){
		int x,y,ans=inf;
		cin>>x>>y;
		for(auto op:g[x])for(auto k:g[y]){
			ans=min(ans,f[op.first][k.first]+op.second+k.second);
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
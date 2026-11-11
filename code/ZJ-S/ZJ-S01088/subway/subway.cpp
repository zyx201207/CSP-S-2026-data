#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,i,j,x,y,k,fx,sx,ans;
int w[510000],vis[510];
int G[510][510],ff[510][510];
vector<int> f[510000],g[510000],F[510];
queue<int> qu;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(i=1;i<=m;i++) cin>>w[i];
    for(i=1;i<=n;i++){
    	cin>>k;
    	for(j=1;j<=k;j++){
    		cin>>x>>y;
    		f[x].push_back(i);
    		g[x].push_back(y);
    	}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i!=j) G[i][j]=1e18;
		}
	}
	for(i=1;i<=m;i++){
		for(j=0;j<f[i].size();j++){
			for(k=0;k<f[i].size();k++){
				if(j==k) continue;
				if(!ff[f[i][j]][f[i][k]]){
					F[f[i][j]].push_back(f[i][k]);
					F[f[i][k]].push_back(f[i][j]);
					ff[f[i][j]][f[i][k]]=1;
					ff[f[i][k]][f[i][j]]=1;
				}
				G[f[i][j]][f[i][k]]=min(G[f[i][j]][f[i][k]],g[i][j]+g[i][k]);
				G[f[i][k]][f[i][j]]=G[f[i][j]][f[i][k]];
			}
		}
	}
	for(j=1;j<=n;j++){
		qu.push(j);
		memset(vis,0,sizeof(vis));
		vis[j]=1;
		while(!qu.empty()){
			fx=qu.front();
			qu.pop();
			for(i=0;i<F[fx].size();i++){
				sx=F[fx][i];
				if(G[j][fx]+G[fx][sx]<=G[j][sx]){
					G[j][sx]=G[j][fx]+G[fx][sx];
					if(!vis[sx]){
						vis[sx]=1;
						qu.push(sx);
					}
				}
			}
		}
	}
	while(q--){
		cin>>x>>y;
		ans=1e18;
		for(i=0;i<f[x].size();i++) for(j=0;j<f[y].size();j++) ans=min(ans,g[x][i]+g[y][j]+G[f[x][i]][f[y][j]]);
		cout<<ans+w[x]+w[y]<<"\n";
	}
}
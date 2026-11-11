#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q;
int w[M];
int t[N][M];
vector<int> g[M];
vector<pair<int,long long> > g2[N];
long long ans=1e18;
long long dfs(int fa,int u,int e,long long sum,long long ans){
	if(u==e){
		return sum;
	}
	for(int i=0;i<g2[u].size();i++){
		int v=g2[u][i].first;
		if(v!=fa){
			ans=min(ans,dfs(u,v,e,sum+g2[u][i].second,ans));
		}
	}
	return ans;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			cin>>x;
			cin>>t[x][i];
			g[x].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=0;k<g[i].size();k++){
				if(k==j){
					continue;
				}
				g2[g[i][j]].push_back({g[i][k],t[i][g[i][k]]+t[i][g[i][j]]});
				g2[g[i][k]].push_back({g[i][j],t[i][g[i][j]]+t[i][g[i][k]]});
			}
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		for(int i=0;i<g[s].size();i++){
			for(int j=0;j<g[e].size();j++){
				ans=min(dfs(0,g[s][i],g[e][j],0,1e18)+w[s]+w[e]+t[s][g[s][i]]+t[e][g[e][j]],ans);
			}
		}
		cout<<ans<<"\n";
		ans=1e18;
	} 
	return 0;
}

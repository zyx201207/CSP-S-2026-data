#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
long long g[505][505];
vector<pair<int,int> >V[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int k,i=1;i<=n;i++){
		cin>>k;
		for(int a,t,j=1;j<=k;j++){
			cin>>a>>t;
			V[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i^j)g[i][j]=1e18;
	for(int i=1;i<=m;i++){
		for(auto it1:V[i]){
			int u=it1.first,w1=it1.second;
			for(auto it2:V[i]){
				int v=it2.first,w2=it2.second;
				if(u^v)g[u][v]=g[v][u]=min(g[u][v],1ll*w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]); 
			}
		}
	}
	while(q--){
		long long ans=LLONG_MAX;
		int x,y;
		cin>>x>>y;
		for(auto it1:V[x]){
			int u=it1.first,w1=it1.second;
			for(auto it2:V[y]){
				int v=it2.first,w2=it2.second;
				ans=min(ans,g[u][v]+w1+w2);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

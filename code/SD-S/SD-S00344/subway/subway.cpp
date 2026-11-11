#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500+10,M=5e5+10;
int c,n,m,d,q,w[N],k[N],a[N][25],t[N][25],vis[M],dis[M];
int s,win;
vector<pair<int,int>>g[N];
void dij(){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pair<int,int>>q1;
	q1.push( {0,s});
	dis[s]=0;
	while(!q1.empty()){
		int nw=q1.top().first,u=q1.top().second;q1.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto i:g[u]){
			int v=i.first,jz=i.second;
			if(dis[v]>dis[u]+jz){
				dis[v]=dis[u]+jz;
				vis[v]=0;
				q1.push({dis[v],v});
			}
		}
	}
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++)
			for(int l=1;l<=k[i];l++){
				if(l==j)continue;
				g[a[i][j]].push_back({a[i][l],t[i][j]+t[i][l]});
			}
	}
	while(q--){
		cin>>s>>win;
		dij();
		cout<<dis[win]+w[s]+w[win]<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int te=1;
//	cin>>te;
	while(te--){
		solve();
	}
	return 0;
}

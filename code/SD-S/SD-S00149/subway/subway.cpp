#include<bits/stdc++.h>
using namespace std;
#define N 505
#define Pii pair<int,pair<int,int> >
const long long inf=1e18; 
int c,n,m,d,q,w[N],k[N],a[N][N],t[N][N];
int dis[N];
bool vis[N];
vector<Pii> g[N];
priority_queue<Pii,vector<Pii>,greater<Pii> > pq; 
int dij(int s,int t1){
	for(int i=1;i<=m;i++) {
		dis[i]=0x3f3f3f3f;
		vis[i]=0;
	}
    dis[s]=0;
    pq.push({dis[s],s});
    while(!pq.empty()){
    	int u=q.top().second.first,c=q.top().second.second;
    	q.pop();
    	if(vis[u]) continue;
    	vis[u]=1;
    	for(auto tmp:g[u]){
    	    int v=tmp.first,c1=tmp.second;
    	    if(dis[v]>dis[u]+t[c][v]){
    	    	dis[v]=dis[u]+t[c][v];
    	    	q.push({dis[v],v});
			}
		}
	}
}
int main(){
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
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++){
			for(int l=j+1;l<=k[i];l++){
				g[a[i][j]].push_back({a[i][l],i});
				g[a[i][l]].push_back({a[i][j],i});
			}
		}
	}	
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dij(x,y)<<'\n';
	}
	return 0;
}


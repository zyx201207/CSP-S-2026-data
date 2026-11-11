#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
const int N=505,M=1e3+5;
int c,n,m,d,q,k;
ll dist[M],cnt[M][M],a[M],t[M],w[M];
bool vis[N];
vector<pii> graph[N];
void ciallo(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int h=j+1;h<=k;h++){
				int u=a[j],v=a[h],w=t[j]+t[h];
				graph[u].push_back({v,w});
				graph[v].push_back({u,w});
			}
		}
	}
}
void floyd(){
	for(int st=1;st<=m;st++){
		memset(dist,0x3f,sizeof dist);
		memset(vis,false,sizeof vis);
		priority_queue<pii,vector<pii>,greater<pii> > q;
		q.push({0,st});
		dist[st]=0;
		vis[st]=1;
		while(!q.empty()){
			int u=q.top().second;
			int d=q.top().first;
			q.pop();
			for(int i=0;i<graph[u].size();i++){
				int v=graph[u][i].first;
				int w=graph[u][i].second;
				
				if(dist[u]+w<d||vis[v]) continue;
				
				if(dist[v]>dist[u]+w){
					vis[v]=true;
					dist[v]=dist[u]+w;
					q.push({dist[v],v});
				}
			}
		}
		for(int j=1;j<=m;j++) 
			cnt[st][j]=dist[j];
	}
}
void solve(){
	int x,y;
	cin>>x>>y;
	ll ans=0;
	ans+=w[x]+w[y];//入站+出站
	floyd();
	ans+=cnt[x][y];
	cout<<ans<<"\n";
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ciallo();
	while(q--){
		solve();
	}
	return 0;
} 
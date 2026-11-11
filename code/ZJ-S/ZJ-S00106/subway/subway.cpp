#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
#define PII pair<int,int>
using namespace std;
const int N=6e3+5,M=1e6+5;
const int INF=0x3f3f3f3f3f3f3f3f;
const int MOD=1e9+7;
int c,n,m,d,q,dis[N][N],w[M],x[M],t[M],vis[N];
vector<PII>g[M];
void dijkstra(int st){
	priority_queue<PII>q;
	for(int i=0;i<=m+1;i++){
		vis[i]=0;
		dis[st][i]=INF;
	}
	dis[st][st]=0;
	q.push({0,st});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto node:g[u]){
			int v=node.first,w=node.second;
			if(dis[st][v]>dis[st][u]+w){
				dis[st][v]=dis[st][u]+w;
				q.push({-dis[st][v],v});
			}
		}
	}
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)cin>>x[j]>>t[j];
		for(int j=1;j<=k;j++){
			for(int l=j+1;l<=k;l++){
				g[x[j]].push_back({x[l],t[j]+t[l]});
				g[x[l]].push_back({x[j],t[j]+t[l]});
			}
		}
	}
	for(int i=1;i<=m;i++)dijkstra(i);
	while(q--){
		int s,t;
		cin>>s>>t;
		cout<<w[s]+w[t]+dis[s][t]<<endl;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

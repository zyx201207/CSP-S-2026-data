#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
vector <int> g[50005];
int dis[50005];
int w[50005];
int t[50005][505],a[505][50005];
int belong[50005];
#define PII pair<int,int>
void dijkstra(int s){
	priority_queue<PII,vector <PII>,greater <PII> > pq;
	memset(dis,0x3f,sizeof dis);
	dis[s]=w[s];
	pq.push({dis[s],s});
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		for(int v : g[u]){
			int tmp=0;
			if(belong[v]!=belong[u])
				tmp=t[u][belong[u]+t[v][belong[v]];
			if(dis[v]>dis[u]+tmp){
				dis[v]=dis[u]+tmp;
				pq.push({dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[a[i][j]][i];
			if(j>1){
				g[a[i][j]].push_back(a[i][j-1]);
				g[a[i][j-1]].push_back(a[i][j]);
			}
			belong[a[i][j]]=i;
		} 
	}
	if(d<=2){
		while(q--){
			int x,y;
			cin>>x>>y;
			dijkstra(x);
			cout<<dis[y]+w[y]<<endl;
		}
	}
	return 0;
}

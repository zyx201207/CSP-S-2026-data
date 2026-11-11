#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d;
int x[2000005];
#define PII pair<int,int>
int dis[5005][5005];
vector <int> g[2000005];
int cnt[5005][5005];
void dijkstra(int s){
	priority_queue<PII,vector <PII>,greater <PII> > pq;
	dis[s][s]=0;
	pq.push({0,s});
	cnt[s][s]=1;
	map <PII,bool> vis;
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		for(int v : g[u]){
			if(dis[s][v]==dis[s][u]+1&&vis[{u,v}]==0) 
				cnt[s][v]++,vis[{u,v}]=1;
			if(dis[s][v]>dis[s][u]+1){
				dis[s][v]=dis[s][u]+1;
				pq.push({dis[s][v],v});
				if(v==t) cnt[s][v]=1;
				vis.clear();
				vis[{u,v}]=1;
			}
		}
	}
}
bool twopath(int u,int v){
	if(dis[u][v]<2) return false;
	return cnt[u][v]==2;	
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof x);
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				cnt[i][j]=1;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
				//else break;
			}
		}
		memset(dis,0x3f,sizeof dis);
		for(int i=1;i<=n;i++)
			dijkstra(i);
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++){
				if(twopath(i,j))
					ans++;
			}
		cout<<ans<<'\n';
	}
	return 0;
}

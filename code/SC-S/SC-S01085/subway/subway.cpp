#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
int c,n,m,d,q;
int w[500005];
int k[505];
int a[505][500005],t[505][500005];
vector<pii> mp[500005*6]; //1~m:站厅 m+i+1:i号线站台

int dist[500005*6],f[500005*6];
priority_queue<pii,vector<pii>,greater<pii>> que;

void dijkstra(int st){
	memset(dist,0x3f,sizeof dist);
	memset(f,0,sizeof f);
	dist[st]=0;
	que.push({0,st});
	while(!que.empty()){
		pii x=que.top();que.pop();
		int u=x.second,dis=x.first;
		if(f[u])continue;
		f[u]=1;
		for(auto it:mp[u]){
			int v=it.first,w=it.second;
			if(dist[v]>dis+w){
				dist[v]=dis+w;
				que.push({dist[v],v});
			}
		}
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
	
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	
	//建边
	for(int i=1;i<=n;i++){ //站厅与站台的边
		for(int j=1;j<=k[i];j++){
			int u=a[i][j],w=t[i][j];
			int v=i+m;
			mp[u].push_back({v,w});
			mp[v].push_back({u,w});
		}
	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<dist[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int c,n,m,d,w[500010];
ll dis[500510],dis2[410][410];
bool vis[500510];
vector<pair<int,int>>edge[500510];
priority_queue<pair<ll,int>>q;
queue<pair<int,int>>q2;
ll sum[500010][3];
void dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=true;
		for(int i=0;i<edge[u].size();i++){
			int v=edge[u][i].first;
			ll val=edge[u][i].second;
			if(dis[u]+val<dis[v]){
				dis[v]=dis[u]+val;
				if(!vis[v]){
					q.push(make_pair(-dis[v],v));
				}
			}
		}
	}
}
int bfs(int x,int y){
	memset(vis,false,sizeof(vis));
	q2.push(make_pair(x,0));
	while(!q2.empty()){
		int u=q2.front().first;
		int d=q2.front().second;
		q2.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=true;
		if(u==y){
			return d;
		}
		for(int i=0;i<edge[u].size();i++){
			int v=edge[u][i].first;
			q2.push(make_pair(v,d+1));
		}
	}
	return -1;
}
int main(){
	// freopen("E:\\down\\subway\\subway5.in","r",stdin);
	// freopen("E:\\down\\subway\\subway5.out","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(7<=c&&c<=8){
		memset(dis2,0x3f,sizeof(dis2));
		for(int i=1;i<=m;i++){
			dis2[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			int k,a1,t1,a2,t2;
			cin>>k>>a1>>t1>>a2>>t2;
			dis2[a1][a2]=min(dis2[a1][a2],(long long)(t1+t2));
			dis2[a2][a1]=min(dis2[a2][a1],(long long)(t1+t2));
		}
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					dis2[i][j]=min(dis2[i][j],dis2[i][k]+dis2[k][j]);
				}
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+dis2[x][y]<<'\n';
		}
		return 0;
	}
	if(12<=c&&c<=15){
		int t;
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int a;
				cin>>a>>t;
				edge[a].push_back(make_pair(i+m,t));
				edge[i+m].push_back(make_pair(a,t));
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+1ll*bfs(x,y)*t<<'\n';
		}
		return 0;
	}
	if(20<=c&&c<=21){
		memset(sum,0x3f,sizeof(sum));
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int a,t;
				cin>>a>>t;
				sum[a][i]=t;
			}
		}
		ll mn=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=m;i++){
			mn=min(mn,sum[i][1]+sum[i][2]);
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<min(min(sum[x][1]+sum[y][1],sum[x][2]+sum[y][2]),
				min(sum[x][1]+mn+sum[x][2],sum[x][2]+mn+sum[x][1]))<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			edge[a].push_back(make_pair(i+m,t));
			edge[i+m].push_back(make_pair(a,t));
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<w[x]+w[y]+dis[y]<<'\n';
	}
	return 0;
}
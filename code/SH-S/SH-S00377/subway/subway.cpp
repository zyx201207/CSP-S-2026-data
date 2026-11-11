#include <bits/stdc++.h>
using namespace std;
int ccc,n,m,d,q;
long long w[500010],dist[500010];
int a[510][510],vis[510];
long long ans[510][510];
vector<pair<int,int>/*i,t*/> c[500010];
vector<pair<int,long long>/*v,w*/> g[510];
void dijkstra(int x){
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	priority_queue<pair<long long,int> ,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
	dist[x]=0;
	pq.push(make_pair(0,x));
	while(!pq.empty()){
		int x=pq.top().second; pq.pop();
		if(vis[x]) continue;
		vis[x]=true;
//		cout<<x<<" "<<dist[x]<<endl;
		for(int i=0;i<g[x].size();i++){
//			cout<<x<<" "<<g[x][i].first<<" "<<g[x][i].second<<" "<<dist[g[x][i].first]<<endl;
			if(dist[g[x][i].first]>dist[x]+g[x][i].second){
				dist[g[x][i].first]=dist[x]+g[x][i].second;
				pq.push(make_pair(dist[g[x][i].first],g[x][i].first));
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans[x][i]=dist[i];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>ccc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k,x,t;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>t;
			c[x].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<c[i].size();j++){
			for(int k=j+1;k<c[i].size();k++){
				a[c[i][j].first][c[i][k].first]=a[c[i][k].first][c[i][j].first]=max(a[c[i][j].first][c[i][k].first],c[i][j].second+c[i][k].second);
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<a[i][j]<<"\n";
			if(a[i][j]){
				g[i].push_back(make_pair(j,a[i][j]));
				g[j].push_back(make_pair(i,a[i][j]));
			}
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
	}
	int xr,yr;
	while(q--){
		cin>>xr>>yr;
		long long minn=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<c[xr].size();i++){
			for(int j=0;j<c[yr].size();j++){
				minn=min(minn,ans[c[xr][i].first][c[yr][j].first]+c[xr][i].second+c[yr][j].second+w[xr]+w[yr]);
			}
		}
		cout<<minn<<"\n";
	} 
	return 0;
}

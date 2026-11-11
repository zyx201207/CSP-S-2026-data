#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int kb[200005];
int a[1005][1005],b[1005][1005];
int e[1005][1005],k[1005],vis[1005];
vector<pair<int,int>> e1[1005];
void dijkstra(int s){
	for(int i=1;i<=m;i++){
		e[s][i]=1e18;
		vis[i]=0;
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({0,s});
	e[s][s]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto id:e1[u]){
			int v=id.first,w=id.second;
			if(e[s][v]>e[s][u]+w){
				e[s][v]=e[s][u]+w;
				q.push({e[s][v],v});
			}
		}
	}
}
void floyd(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>kb[i];
	}
	if(c<=6){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i!=j){
					e[i][j]=1e18;
				}
			}
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j]>>b[i][j];
				for(int kk=1;kk<j;kk++){
					e[a[i][j]][a[i][kk]]=b[i][j]+b[i][kk];
					e[a[i][kk]][a[i][j]]=b[i][j]+b[i][kk];
				}
			}
		}
		floyd();
		while(q--){
			int x,y;cin>>x>>y;
			cout<<e[x][y]+kb[x]+kb[y]<<"\n";
		}		
	} 
	else{
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j]>>b[i][j];
			}
			e1[a[i][1]].push_back({a[i][2],b[i][1]+b[i][2]});
			e1[a[i][2]].push_back({a[i][1],b[i][1]+b[i][2]});
		}
		for(int i=1;i<=m;i++){
			dijkstra(i);
		}
		while(q--){
			int x,y;cin>>x>>y;
			cout<<e[x][y]+kb[x]+kb[y]<<"\n";
		}
	}
} 

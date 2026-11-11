#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,D,Q,W[500005],k[505],f[505][505],dis[505][505],t[505][50005];
vector<int> a[505],nd[500005];
struct node{
	int dis,u,ln;
	bool operator > (const node &t) const {
		return dis>t.dis;
	}
};
void Dijkstra(int x){
	priority_queue<node,vector<node>,greater<node>> q;
	for(int i=1;i<=n;i++) dis[x][i]=0x3f3f3f3f3f3f3f3f;
	dis[x][x]=0;
	for(int i:a[x]){
		q.push({0,i,x});
	}
	while(!q.empty()){
		int u=q.top().u,ln=q.top().ln;
		q.pop();
		for(int v: nd[u]){
			if(ln==v) continue;
			if(dis[x][v]>dis[x][ln]+t[ln][u]+t[v][u]){
				dis[x][v]=dis[x][ln]+t[ln][u]+t[v][u];
				for(int i=1;i<=k[v];i++){
				if(a[v][i]==u) continue;
//					cout<<x<<" "<<u<<" "<<ln<<" "<<v<<" "<<dis[x][v]<<" "<<dis[x][ln]<<" "<<t[ln][u]<<" "<<t[v][u]<<"\n";
					q.push({dis[x][v],a[v][i],v});
				}
			}
			
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int TC; cin>>TC;
	cin>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int x,y; cin>>x>>y;
			a[i].push_back(x),t[i][x]=y;
			nd[x].push_back(i);
//			cout<<i<<" "<<x<<" "<<y<<"\n";
		}
	}
	for(int i=1;i<=n;i++){
		Dijkstra(i);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	while(Q--){
		int sx,sy,ans=1e18;
		cin>>sx>>sy;
//		cout<<sx<<" "<<sy<<" ";
		for(int i:nd[sx]){
			for(int j:nd[sy]){
//				cout<<i<<" "<<j<<"\n";
				ans=min({ans,dis[i][j]+(W[sx]+W[sy])+(t[i][sx]+t[j][sy])});
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

const int N=1e3+5;
const long long inf=0x3f3f3f3f3f3f3f3f;

int c,n,m,d,q;

int w[N],a[N],v[N];

struct node{int a,b;};
vector<node> G[N];

bool vis[N];
long long dis[N][N];

struct wcy{
	int u;
	long long d;
	
	bool operator <(wcy x) const{
		return d>x.d;
	}
};

void dijkstra(int s){
	fill(vis+1,vis+m+1,0);
	fill(dis[s]+1,dis[s]+m+1,inf);
	
	priority_queue<wcy> qu;
	
	dis[s][s]=0;
	qu.push({s,0});
	
	while(!qu.empty()){
		wcy nw=qu.top(); qu.pop();
		
		int u=nw.u;
		long long d=nw.d;
		
//		cout<<u<<" "<<d<<" "<<endl;
		
		if(vis[u]) continue;
		vis[u]=1;
		
		for(auto it:G[u]){
			int v=it.a;
			long long w=it.b;
			
			if(d+w<dis[s][v]){
				dis[s][v]=d+w;
				qu.push({v,d+w});
			}
		}
	}
}

int main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++) cin>>w[i];
	
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++) cin>>a[j]>>v[j];
		
		for(int j=1;j<=k;j++){
			for(int l=j+1;l<=k;l++){
				G[a[j]].push_back({a[l],v[j]+v[l]});
				G[a[l]].push_back({a[j],v[j]+v[l]});
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		dijkstra(i);
	}
	
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<dis[i][j]<<" ";
//		}cout<<endl;
//	}
	
	while(q--){
		int u,v;
		cin>>u>>v;
		
		cout<<dis[u][v]+w[u]+w[v]<<endl;
	}

	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/


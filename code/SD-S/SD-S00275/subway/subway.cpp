#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
struct Edge{
	int to,w;
	friend bool operator<(Edge a,Edge b){
		return a.w<b.w;
	}
	friend bool operator>(Edge a,Edge b){
		return a.w>b.w;
	}
};
int c,n,m,d,q,w[N];
vector<Edge>g[1010];
int dis[1010][1010];
bitset<1010>f;
void dy_dij(){
	for(int s=1;s<=m;s++){
		for(int i=1;i<=m;i++)dis[s][i]=0x3f3f3f3f3f3f3f3f,f[i]=0;
		dis[s][s]=0;
		priority_queue<Edge,vector<Edge>,greater<Edge> >q;
		q.push({s,0});
		while(q.size()){
			int x=q.top().to;q.pop();
			if(f[x])continue;
			f[x]=1;
			for(Edge e:g[x]){
				if(dis[s][x]+e.w<dis[s][e.to]){
					dis[s][e.to]=dis[s][x]+e.w;
					q.push({e.to,dis[s][e.to]});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(1<=c&&c<=6){
		for(int i=1,k;i<=n;i++){
			cin>>k;
			for(int j=1,a,t;j<=k;j++){
				cin>>a>>t;
				g[i+m].push_back({a,t});
				g[a].push_back({i+m,t});
			}
		}
		m+=n;
		dy_dij();
		for(int i=1,x,y;i<=q;i++){
			cin>>x>>y;
			cout<<dis[x][y]+w[x]+w[y]<<'\n';
		}
	}
	if(7<=c&&c<=11){
		for(int i=1,k,u,v,w1,w2;i<=n;i++){
			cin>>k>>u>>w1;
			if(k==1)continue;
			cin>>v>>w2;
			g[u].push_back({v,w1+w2});
			g[v].push_back({u,w1+w2});
		}
		dy_dij();
		for(int i=1,x,y;i<=q;i++){
			cin>>x>>y;
			cout<<dis[x][y]+w[x]+w[y]<<'\n';
		}
		return 0;
	}
	
	return 0;
}
/*
2 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/

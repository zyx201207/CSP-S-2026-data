#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e16;
int c,n,m,d,q;
int w[500005];
struct Edge{
	int v,w;
};
vector<Edge>g[1100005];
int tot;
int dis[1100005];
bool vis[1100005];
int Ans[2005][2005];
struct Node{
	int u,d;
	bool operator < (Node you)const{
		return d>you.d;
	}
};
priority_queue<Node>pq;
//int getky(int u,int v){
//	u<<=32;
//	return u+v;
//}
//unordered_map<int,int>ans;
void dij(int s){
	while(pq.size())pq.pop();
	for(int i = 1;i<=2*m+n;i++){
		dis[i] = inf;
		vis[i] = 0;
	}
	dis[s] = 0;
	pq.push({s,0});
	while(pq.size()){
		int u = pq.top().u;
		int d = pq.top().d;
		pq.pop();
		if(vis[u])continue;
		vis[u] = 1;
		for(auto it:g[u]){
			int v = it.v;
			int w = it.w;
			if(dis[v]>d+w){
				dis[v] = d+w;
				if(!vis[v])pq.push({v,d+w});
			}
		}
	}
//	cout<<"dij end ";
//	for(int i = 1;i<=2*m+n;i++){
//		if(!ans.count(getky(s,i)))ans[getky(s,i)] = ans[getky(i,s)] = dis[i];
//	}
}
signed main(){
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
		int k = i*2-1;
		int z = i*2;
		g[k].push_back({z,w[i]});
		g[z].push_back({k,w[i]});
	}
	tot = 2*m;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		int zhan = tot+i;
		for(int j = 1;j<=k;j++){
			int a,T;
			cin>>a>>T;
			int to = a*2;
			g[zhan].push_back({to,T});
			g[to].push_back({zhan,T});
		}
	}
//	cerr<<(n+2*m)*m<<" "<<q<<'\n';
	if(m<q){
//		cerr<<"111";
		for(int i = 1;i<=m;i++){
			dij(i*2-1);
			for(int j = 1;j<=m;j++){
				Ans[i][j] = dis[j*2-1];
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<Ans[x][y]<<'\n';
		}
		return 0;
	}
	while(q--){
		int x,y;
		cin>>x>>y;
//		if(ans.count(getky(x,y))){
//			cout<<ans[getky(x,y)]<<'\n';
//			continue;
//		}
//		cout<<q<<' ';
		dij(x*2-1);
		cout<<dis[y*2-1]<<'\n';
	}
//	cout<<"END";
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

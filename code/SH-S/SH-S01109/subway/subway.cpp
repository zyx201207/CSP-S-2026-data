#include<bits/stdc++.h>

// 1hr 15mins with T2 32pts(?)
// expected: 32pts

using namespace std;

struct Node{
	int v;
	long long t;
	bool operator >(const Node other) const{
		return t > other.t;
	}
};
long long w[500010];
vector<vector<int> > pas(500010);
map<int,long long> sta[500010]; // the line of a station and the walking time
long long k[510];
priority_queue<Node,vector<Node>,greater<Node> > pq;// the time it takes to reach the hub of a sta.
long long dis[500010];

void dijkstra(){
	while(pq.size()){
		auto f = pq.top(); pq.pop();
		if(f.t > dis[f.v]) continue;
		// move
		for(auto x: sta[f.v]){
			int nd = f.t+x.second;
			for(auto y: pas[x.first]){
				if(nd+sta[y][x.first] < dis[y]){
					dis[y] = nd+sta[y][x.first];
					pq.push({y,nd+sta[y][x.first]});
				}
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	long long c,n,m,d,q; cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++){
			int a,t; cin >> a >> t;
			sta[a][i] = t;
			pas[i].push_back(a);
		}
	}
	
	while(q --){
		int x,y; cin >> x >> y;
		// init
		memset(dis,0x3f,sizeof dis);
		//
		pq.push({x,0});
		dijkstra();
		cout << dis[y]+w[x]+w[y] << '\n';
	}
	
	return 0;
}

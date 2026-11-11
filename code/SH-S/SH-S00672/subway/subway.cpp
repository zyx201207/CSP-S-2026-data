#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll c,n,m,d,q;

// for distances, 0 stands for station, 1 stands for lines
// for edges, 0 stands for line to station(collected by line id), 1 stands for station to line(collected by station id)
// so, when one get a edge, he can set the distance exactly to the type of edge.
// meanwhile, if one get a edge and want to get the following edges, he must use [!type] and [id]

struct edge{
	ll to,w;
	bool type;//0:line to station, 1: station to line, number will stand for target types
	const bool operator< (const edge& other)const{
		return w>other.w;
	}
};

edge make_edge(ll to,ll w, bool type){
	edge e;
	e.to=to;
	e.w=w;
	e.type=type;
	return e;
}

unordered_map<ll,unordered_map<ll,edge>> edges[2];//0: line to station edges, id is line, 1: station to line edges, id is station
unordered_map<ll,ll> downs;

ifstream fin("subway.in");
ofstream fout("subway.out");

ll dijkstra(ll s,ll e){
    map<ll,ll> dist[2];//0:station distances, 1:line distances
	priority_queue<edge> pq;
	pq.push(make_edge(s,0,0));
	while(!pq.empty()){
        edge cur=pq.top();
        pq.pop();
        if((!cur.type)&&(cur.to==e))return cur.w;
        if(dist[cur.type].find(cur.to)!=dist[cur.type].end())
            continue;
		dist[cur.type][cur.to]=cur.w;
        for(const auto& kvp:edges[!cur.type][cur.to]){
        	edge i=kvp.second;
            if(dist[i.type].find(i.to)!=dist[i.type].end())continue;
            ll curw=cur.w+i.w;
            pq.push(make_edge(i.to,curw,i.type));
        }
	}
	auto it=dist[0].find(e);
	if(it==dist[0].end())return -1;
	return it->second;
}

void solve(){
	ll x,y;
	fin>>x>>y;
	fout<<(dijkstra(x,y)+downs[x]+downs[y])<<endl;
}

int main(){
	fin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		ll st;
		fin>>st;
		downs[i]=st;
	}
	for(ll i=1;i<=n;i++){
		ll k;
		fin>>k;
		while(k--){
			ll a,l;//a for station number, i for line number, l for length
			fin>>a>>l;
			edges[0][i][a]=make_edge(a,l,false);
			edges[1][a][i]=make_edge(i,l,true);
		}
	}
	while(q--){
		solve();
	}
}

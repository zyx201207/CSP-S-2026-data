#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
const ll inf=1e14;
ll c,n,m,d,q;
vll w,lyr;
ll get(ll sta,ll h){
	return (sta-1)*d+h;
}

struct node{
	ll v,w;
	node(ll _v,ll _w):v(_v),w(_w){}
	friend bool operator<(node x,node y){
		return x.w>y.w;
	}
};
vector<vector<node>>e;
vll dis,vis;
void addedge(ll u,ll v,ll w){
//	cerr<<"u="<<u<<", v="<<v<<", w="<<w<<endl;
	e[u].emplace_back(v,w);
	e[v].emplace_back(u,w);
}
void D(ll s){
	priority_queue<node>pq;
	pq.emplace(s,0);
	fill(dis.begin(),dis.end(),inf);
	fill(vis.begin(),vis.end(),0);
	dis[s]=0;
	while(pq.size()){
		auto ux=pq.top();
		ll u=ux.v,x=ux.w;
		pq.pop();
		if(!vis[u]){
			vis[u]=1;
			for(auto vw:e[u]){
				ll v=vw.v,w=vw.w;		
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
//					cout<<"pq.emplace("<<v<<","<<dis[v]<<")\n";
					pq.emplace(v,dis[v]);
				}
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
	e.resize(m*(d+2)),dis.resize(m*(d+2)),vis.resize(m*(d+2));
//	cerr<<"size="<<e.size()<<endl;
	w.resize(m+1,1);
	lyr.resize(m+1,1);//记录这个地铁站堆了多少层，初始为大厅一层 
	//一个节点的编号 = (这个点所在的地铁站编号-1) * d + 它的层数
	//特别地，(这一层的大厅 = 地铁站编号-1) * d + 1 
	//我们需要记录每个站点各自的编号 
	//最大节点数 = 地铁站数 * 层数 = n(d+1)
	//定义外界为 0 号节点
	//每个地铁站的大厅和外界连一条单向边
	//最终到的是 终点的站厅（而非外界）  
	for(ll i=1;i<=m;i++){
		cin>>w[i];
//		e[0].emplace_back(get(i,1),w[i]);
	}
	for(ll i=1,k;i<=n;i++){
		cin>>k;
		vll seq;
		for(ll p=1,st,tim,num;p<=k;p++){
			cin>>st>>tim;
			lyr[st]++,num=get(st,lyr[st]);
			seq.emplace_back(num);
			addedge(get(st,1),num,tim);
		}
		for(ll st=1;st<seq.size();st++){
			addedge(seq[st-1],seq[st],0);
		}
	}
//	D(0);
	// 从外界走到终点的站厅，其最短路不一定与起点到终点的最短路相同
	//  
	for(ll i=1,x,y;i<=q;i++){
		cin>>x>>y;
//		cerr<<"from "<<get(x,1)<<" to "<<get(y,1)<<":\n"; 
		D(get(x,1));
//		cout<<"dis="<<dis[get(y,1)]<<endl;
		cout<<dis[get(y,1)]+w[x]+w[y]<<endl;
	}
}


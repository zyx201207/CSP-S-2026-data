#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAXM 500005
#define MAXN 505
/*
m个点的连通无重边图
每站有点权
	地铁口到站厅 w i
	站厅到第j线路的站台 t i,j 
每站最多有d条线路

对于每个q 
求 xi的口 到 yi的口 +最短路 
*/
ll c,n,m,d,q;
ll k[MAXM];
struct Side{
	//u到v的一条边 
	int v;
	//边权 
	int t;	
	bool operator >(Side& other) {
		return t>other.t;
	}
	bool operator <(Side& other) {
		return t<other.t;
	}
};
struct Cmp
    {
      bool
      operator()(const Side& __x, const Side& __y) 
      { return __x.t > __y.t; }
    };
bool cmp(const Side& a,const Side& b){
	return bool(a.t>b.t);
}
struct Node{
	vector<Side> vs;//到站台v的一条边 
	ll w=-1;//到站厅 
};
vector<Node> mapp(MAXN+MAXM);
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&mapp[i].w);
//		cin>>mapp[i].w;
	}
	int rootcnt=MAXM;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			int v;
			int t;
			scanf("%d%d",&v,&t);
//			cin>>v>>t;
			mapp[v].vs.push_back({rootcnt,t});
			mapp[rootcnt].vs.push_back({v,t});
		}
		rootcnt++;
	}
//	for(int u=0;u<m;u++){
//		for(auto v:mapp[u].vs){
//			cout<<u<<" "<<v.v<<"\n";
//		}
//	}
	for(int _i=0;_i<q;_i++){
		int x,y;
		scanf("%d%d",&x,&y);
//		cin>>x>>y;
		int ans=mapp[x].w+mapp[y].w;
		//缔结特斯tra 
		priority_queue<Side,vector<Side>,Cmp> minq;
		minq.push({x,0});
		vector<ll> path(MAXM+MAXN,1e18);
		path[x]=0;
		while(!minq.empty()) {
			int u=minq.top().v;
			minq.pop();
			for(auto& v:mapp[u].vs){
//				cout<<u<<"-"<<v.v<<"_:_"<<path[v.v]<<"_"<<path[u]<<" | "<<path[u]+v.t<<"\n";
				if(path[v.v]>path[u]+v.t){
//					cout<<"update\n\n";
					path[v.v]=path[u]+v.t;
					minq.push(v);
				}
			}
		}
		printf("%d\n",ans+path[y]);
//		cout<<ans+path[y]<<"\n";
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node{
	ll u,dist;
	bool operator >(const Node &a)const{
		return dist>a.dist;
	};
};
struct Edge{
	ll v,w;
};
ll c,n,m,d,q,_,__,___;
ll wl[514511],dis[514511];
vector<Edge> ad[514511];
priority_queue<Node,vector<Node>,greater<Node>> pq;
inline ll dij(int x,int y){
	for(int i=1;i<=m+n;i++)dis[i]=11451419198;
	pq.push({x,0});
	dis[x]=0;
	while(!pq.empty()){
		Node p=pq.top();
		pq.pop();
		for(int i=0;i<ad[p.u].size();i++){
			Edge vt=ad[p.u][i];
			if(dis[vt.v]>vt.w+dis[p.u]){
				pq.push({vt.v,vt.w+dis[p.u]});
				dis[vt.v]=vt.w+dis[p.u];
			}
		}
	}
	return dis[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>wl[i];
	for(int i=1;i<=n;i++){
		cin>>_;
		while(_--){
			cin>>__>>___;
			ad[i].push_back({n+__,___});
			ad[n+__].push_back({i,___});
		}
	}
	while(q--){
		cin>>_>>__;
//		scanf("%lld",&_,&__);
//		printf("%lld \n",dij(n+_,n+__)+wl[_]+wl[__]);
		cout<<dij(n+_,n+__)+wl[_]+wl[__]<<'\n';
	}
	return 0;
}


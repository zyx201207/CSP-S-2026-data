#include <bits/stdc++.h>
using namespace std;
#define M 500005
#define ll long long
int c,n,m,d,q;
ll ct,tk[M][2],dis[22*M],vis[22*M];
struct Edge{
	ll v,w;
	bool operator <(const Edge &x)const{return w>x.w;}
	bool operator >(const Edge &x)const{return w<x.w;}
};
vector<Edge> e[22*M];
int main(void){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		ll w;
		cin>>w;
		tk[i][0]=++ct,tk[i][1]=++ct;
		e[tk[i][0]].push_back(Edge{tk[i][1],w});
		e[tk[i][1]].push_back(Edge{tk[i][0],w});
	}
	
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		++ct;
		for(int j=1;j<=k;j++){
			ll x,t;
			cin>>x>>t;
			e[ct].push_back(Edge{tk[x][1],t});
			e[tk[x][1]].push_back(Edge{ct,t});
		}
	}
	for(int qq=1;qq<=q;qq++){
		ll x,y;
		cin>>x>>y;
		priority_queue<Edge> p;
		for(int i=1;i<=ct;i++)dis[i]=1e18,vis[i]=0;
		dis[tk[x][0]]=0;
		p.push(Edge{tk[x][0],0});
		while(!p.empty()){
			ll nx=p.top().v,nw=p.top().w;
			p.pop();
			if(vis[nx]==1)continue;
			vis[nx]=1;
			for(int i=0;i<e[nx].size();i++){
				ll nk=e[nx][i].v,kw=e[nx][i].w;
				if(vis[nk]==1)continue;
				if(dis[nk]>=nw+kw){
					dis[nk]=nw+kw;
					p.push(Edge{nk,dis[nk]});
				}
			}
		}
		cout<<dis[tk[y][0]]<<"\n";
	}
	return 0;
}


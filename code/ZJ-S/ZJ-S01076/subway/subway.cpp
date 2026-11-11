#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+5,N=505;
ll C,n,m,d,q;
ll w[M],k[M],a[M],t[M],dis[1505][1505];
struct node{
	ll v,w;
	bool operator<(const node &s)const{
		return s.w<w;
	}
};
vector<node>g[M+N];
void dij(ll s){
	priority_queue<node>q;
	q.push({s,0});
	dis[s][s]=0;
	while(q.size()){
		node p=q.top();
		q.pop();
		for(auto t:g[p.v]){
			if(dis[s][t.v]>dis[s][p.v]+t.w){
				dis[s][t.v]=dis[s][p.v]+t.w;
				q.push({t.v,dis[s][t.v]});
			}
		}
	}
}
void solve1(){
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k[i];j++){
			g[a[j]].push_back({i+m,t[j]});
			g[i+m].push_back({a[j],t[j]});
		}
	}
	for(int i=1;i<=m+n;i++){
		for(int j=1;j<=m+n;j++){
			dis[i][j]=2e18;
		}
	}
	for(int i=1;i<=m;i++){
		dij(i);
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0);
	cin>>C>>n>>m>>d>>q;
	solve1();
	return 0;
}
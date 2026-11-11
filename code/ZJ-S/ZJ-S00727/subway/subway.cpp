#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int lu=5e5;
int C,n,m,D,q;
int kow[500005];
vector<pair<int,int> > e[500505];
map<int,ll> dis[500505];
bool vis[500505];
struct node{
	int u;ll w;
	bool operator<(const node &a)const{return a.w<w;}
};
void dij(int st){
	for(int i=1;i<=m;i++)vis[i]=0;
	for(int i=1;i<=n;i++)vis[lu+i]=0;
	priority_queue<node> q;
	q.push({st,0});
	dis[st][st]=0;vis[st]=1;
	while(q.size()){
		node t=q.top();q.pop();
		for(auto i:e[t.u]){
			if(!vis[i.fi]&&(t.w+i.se<dis[st][i.fi]||dis[st][i.fi]==0)){
				dis[st][i.fi]=t.w+i.se;vis[i.fi]=1;
				q.push({i.fi,dis[st][i.fi]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>kow[i];
	for(int i=1;i<=n;i++){
		int ki;cin>>ki;
		for(int j=1;j<=ki;j++){
			int x,w;cin>>x>>w;
			e[lu+i].push_back({x,w});
			e[x].push_back({lu+i,w});
		}
	}
	for(int i=1;i<=q;i++){
		int st,en;cin>>st>>en;
		if(!dis[st][en])dij(st);
		if(st==en)cout<<2*kow[st]<<'\n';
		else cout<<dis[st][en]+kow[st]+kow[en]<<'\n';
	}
	return 0;
}

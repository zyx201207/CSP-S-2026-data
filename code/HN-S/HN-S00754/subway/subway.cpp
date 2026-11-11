#include<bits/stdc++.h>
#define ll long long
using namespace std;
int w[500005];
vector<int> g[500005];
vector<ll> gw[500005];
ll dis[500005];
bool vis[500005];
struct node{
	int x;
	ll d;
	bool operator <(const node t)const{
		return d>t.d;
	}
};
priority_queue<node> q;
inline ll dijkstra(int st,int ed){
	for(int i=0;i<500000;i++) dis[i]=1e18;
	memset(vis,0,sizeof vis);
	dis[st]=0;
	q.push({st,0});
	while(!q.empty()){
		int u=q.top().x;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			ll w=gw[u][i];
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
	return dis[ed];
}
int main(){
	int c,n,m,d,q;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		vector<int> v1;
		vector<ll> v2;
		cin >> k;
		for(int i=1;i<=k;i++){
			int x;
			ll y;
			cin >> x >> y;
			v1.push_back(x);
			v2.push_back(y);
		}
		for(int i=0;i<k;i++){
			for(int j=0;j<k;j++){
				g[v1[i]].push_back(v1[j]);
				gw[v1[i]].push_back(v2[i]+v2[j]);
			}
		}
	}
	while(q--){
		int st,ed;
		cin >> st >> ed;
		cout << dijkstra(st,ed)+w[st]+w[ed] << '\n';
	}
	return 0;
}

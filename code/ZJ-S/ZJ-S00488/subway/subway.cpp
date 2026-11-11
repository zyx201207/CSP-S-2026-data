#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e4+10;
int a[N];
int c,m,n,d,q,st,ed;
struct edge{
	int to,w;
	bool operator < (const edge & b) const {
		return w>b.w;
	}
};
vector<edge>e[N+510];
int dis[N+510];
void Dijkstra(){
	memset(dis,0x7f,sizeof(dis));
	priority_queue<edge>q;
	dis[st]=0;
	q.push({st,0});
	while(!q.empty()){
		edge t=q.top();
		q.pop();
		if(t.to==ed){
			cout << t.w+a[st]+a[ed] << '\n';
			return ;
		}
		if(t.w>dis[t.to]) continue;
		for(auto v:e[t.to]){
			int to=v.to,w=v.w;
			if(dis[to]>dis[t.to]+w){
				dis[to]=dis[t.to]+w;
				q.push({to,dis[to]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> m >> n >> d >> q;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=m;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int now,t;
			cin >> now >> t;
			e[now].push_back({n+i,t});
			e[n+i].push_back({now,t});
		}
	}
	while(q--){
		cin >> st >> ed;
		Dijkstra();
	}
	return 0;
}


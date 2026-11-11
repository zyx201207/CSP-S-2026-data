#include<bits/stdc++.h>
#define ll long long
#define pil pair<int,ll>
#define pli pair<ll,int>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 10,M = 5e5 + 10;
int c,n,m,q,id;
ll w[M];
int d[M];
vector<pil> g[N];
ll dis[N];
bool vis[N];
struct st{
	int id,x,y;
	ll ans;
}qr[100010];
bool cmp1(st A,st B){return A.x < B.x;}
bool cmp2(st A,st B){return A.id < B.id;}
void dijk(int st){
	priority_queue<pli,vector<pli>,greater<pli>> pq;
	memset(vis,0,sizeof(bool) * (id + 1));
	memset(dis,0x3f,sizeof(ll) * (id + 1));
	dis[st] = 0;
	pq.push({dis[st],st});
	while(!pq.empty()){
		int u = pq.top().se;
		pq.pop();
		if(vis[u])
			continue;
		vis[u] = 1;
		for(pil x : g[u]){
			int v = x.fi;
			ll w = x.se;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				pq.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> c >> q;
	for(int i = 1 ; i <= m ; i ++)
		cin >> w[i];
	id = m;
	for(int i = 1 ; i <= n ; i ++){
		int k;
		cin >> k;
		for(int j = 1,u,v ; j <= k ; j ++){
			ll t;
			cin >> v >> t;
			id ++;
			if(j >= 2){
				g[id].push_back({id - 1,0});
				g[id - 1].push_back({id,0});
			}
			g[v].push_back({id,t});
			g[id].push_back({v,t});
			u = v;
		}
	}
	for(int i = 1,x,y ; i <= q ; i ++){
		cin >> x >> y;
		qr[i] = {i,min(x,y),max(x,y),0};
	}
	sort(qr + 1,qr + 1 + q,cmp1);
	for(int i = 1 ; i <= q ; i ++){
		if(qr[i].x != qr[i - 1].x)
			dijk(qr[i].x),qr[i].ans = dis[qr[i].y] + w[qr[i].x] + w[qr[i].y];
		else
			qr[i].ans = dis[qr[i].y] + w[qr[i].x] + w[qr[i].y];
	}
	sort(qr + 1,qr + 1 + q,cmp2);
	for(int i = 1 ; i <= q ; i ++)
		cout << qr[i].ans << '\n';
	return 0;
}
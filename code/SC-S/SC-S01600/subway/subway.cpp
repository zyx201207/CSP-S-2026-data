#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int maxn = 5e5 + 5;
int c,n,m,d,q,x[maxn],y[maxn],dis[maxn * 20],s,e;
bool vis[maxn * 20];
vector<pair<int,ll> > G[maxn * 20];
vector<int> line[maxn];//line -> 每个点经过哪些线路
ll w[maxn],t[maxn * 20];
void init(){
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++) cin>>w[i];
	for(int i = 1;i <= n;i++){
		int k,a[maxn];
		cin>>k;
		for(int j = 1;j <= k;j++){
			cin>>a[j];//a[j]为站台编号
			cin>>t[a[j] + m * i - m];//m * i - m代表第i条线路
			for(auto num : line[a[j]]){
				G[a[j] + m * i - m].push_back({a[j] + m * num - m,t[a[j] + m * i - m]+t[a[j] + m * num - m]});
				G[a[j] + m * num - m].push_back({a[j] + m * i - m,t[a[j] + m * i - m]+t[a[j] + m * num - m]});
			}
			if(j > 1){
				G[a[j - 1] + m * i - m].push_back({a[j] + m * i - m,0});
				G[a[j] + m * i - m].push_back({a[j - 1] + m * i - m,0});
			}
			line[a[j]].push_back(i);
		}
	}
	for(int i = 1;i <= q;i++) cin>>x[i]>>y[i];
}
void Dijkstra(){
	memset(dis,0x3f3f3f3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	dis[s] = 0;
	pq.push({0,s});
	while(!pq.empty()){
		auto tmp = pq.top();pq.pop();
		int u = tmp.second;
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto tmp2:G[u]){
			int v = tmp2.first;
			ll val = tmp2.second;
			if(dis[v] > dis[u] + val){
				dis[v] = dis[u] + val;
				if(u == s) dis[v] += t[u % m + (v / m) * m];
				pq.push({dis[v],v});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	for(int i = 1;i <= q;i++){
		e = y[i];
		for(auto num:line[x[i]]){
			s = x[i] + num * m - m;
			Dijkstra();
		}
		int ans = INT_MAX;
		for(auto num:line[y[i]]){
			ans = min((long long)ans,dis[y[i] + m * num - m] + t[y[i] + num * m - m]);
		}
		cout<<ans + w[x[i]] + w[y[i]]<<'\n';
	}
	return 0;
}
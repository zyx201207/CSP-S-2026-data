#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500005;
const ll inf = 1000000000000000000;
int qc, n, m, d, q, cnt;
ll w[N], dis[N];
bool vis[N];
struct node{
	int to;
	ll v;
	bool operator < (const node &s)const{
		return v > s.v;
	}
};
vector <node> g[N];
void add(int x, int y, ll v){
	g[x].push_back({y, v});
	g[y].push_back({x, v});
}
void dij(int st){
	for(int i = 1;i <= cnt;i++){
		vis[i] = 0;
		dis[i] = inf;
	}
	priority_queue <node> q;
	dis[st] = 0;
	q.push({st, 0});
	while(!q.empty()){
		node t = q.top();
		q.pop();
		int p = t.to;
		if(vis[p])continue;
		vis[p] = 1;
		for(auto t : g[p]){
			int x = t.to;ll v = t.v;
			if(dis[x] > dis[p] + v){
				dis[x] = dis[p] + v;
				q.push({x, dis[x]});
			}
		}
	}
}
void bfs(int st){
	for(int i = 1;i <= cnt;i++){
		vis[i] = 0, dis[i] = inf;
	}
	deque <int> q;
	dis[st] = 0;
	q.push_back(st);
	while(!q.empty()){
		int p = q.front();
		q.pop_front();
		if(vis[p])continue;
		vis[p] = 1;
		for(auto t : g[p]){
			int x = t.to;ll v = t.v;
			if(dis[x] > dis[p] + v){
				dis[x] = dis[p] + v;
				if(v)q.push_back(x);
				else q.push_front(x);
			}
		}
	}
}
void s1(){
	for(int i = 1;i <= m;i++){
		int k;scanf("%d", &k);
		int lst = 0;
		for(int j = 1;j <= k;j++){
			int p;ll v;
			scanf("%d%lld", &p, &v);
			add(p, ++cnt, v);
			if(lst)add(cnt, lst, 0);
			lst = cnt;
		}
	}
	while(q--){
		int x, y;
		scanf("%d%d", &x, &y);
		dij(x);
		printf("%lld\n", dis[y] + w[x] + w[y]);
	}
}
void s2(){
	for(int i = 1;i <= m;i++){
		int k;scanf("%d", &k);
		int lst = 0;
		for(int j = 1;j <= k;j++){
			int p;ll v;
			scanf("%d%lld", &p, &v);
			add(p, ++cnt, v);
			if(lst)add(cnt, lst, 0);
			lst = cnt;
		}
	}
	while(q--){
		int x, y;
		scanf("%d%d", &x, &y);
		bfs(x);
		printf("%lld\n", dis[y] + w[x] + w[y]);
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &qc, &m, &n, &d, &q);
	cnt = n;
	for(int i = 1;i <= n;i++){
		scanf("%lld", &w[i]);
	}
	if(12 <= qc && qc <= 15){
		s2();
	}else{
		s1();
	}
	return 0;
}
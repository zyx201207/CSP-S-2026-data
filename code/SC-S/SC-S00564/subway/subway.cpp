#include<bits/stdc++.h>
#define pii pair<int, int> 
#define fi first
#define sec second
using namespace std;
const int N = 502;
const int M = 2e5 + 2;
const int inf = 1e9;
int ztcnt = M >> 1;
struct node{
	int to, nxt, w;
} pic[M << 1];
int head[M], cnt;
void add(int u, int v, int w){
	pic[cnt].to = v;
	pic[cnt].nxt = head[u];
	pic[cnt].w = w;
	head[u] = cnt ++;
}
int w[M];
//int ti[N][M];
int dis[M];
void bfs(int st, int ed){
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({0, st});
	dis[st] = 0;
	while(!pq.empty()){
		pii nw = pq.top();
		pq.pop();
		for(int i = nw.sec; i != -1; i = pic[i].nxt){
			int nt = pic[i].to;
			if(nt == 0) continue;
			if(dis[nt] > nw.fi + pic[i].w){
				dis[nt] = nw.fi + pic[i].w;
				pq.push({dis[nt], nt});
			}
		}
	}
}
map<int, int> mp;
map<int, map<int, bool> > flag;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int c, n, m, d, qq;
	cin >> c >> n >> m >> d >> qq;
	memset(head, -1, sizeof(head));
	for(int i = 1; i <= m; i ++){
		cin >> w[i];
	}
	for(int i = 0; i < n; i ++){
		int k, lst[2] = {0, 0};
		cin >> k;
		for(int j = 0; j < k; j ++){
			int u, t;
			cin >> u >> t;
//			ti[i][u] = t;
			if(flag[i - 1][u]){
				add(lst[0], u, lst[1] + t);
				add(u, lst[0], lst[1] + t);
				/*
				ztcnt ++;
				add(lst[0], ztcnt, lst[1]);
				add(ztcnt, lst[0], lst[1]);
				add(ztcnt, u, t);
				add(u, ztcnt, t);
				*/
			} else if(j != 0){
				add(lst[0], u, 0);
				add(u, lst[0], 0);
			}
			flag[i][u] = 1;
			lst[0] = u, lst[1] = t;
			mp[u] = t;
		}
	}
	while(qq --){
		int u, v;
		cin >> u >> v;
		int ans = w[u] + w[v] + mp[u] + mp[v];
		for(int i = 0; i <= (M >> 1); i ++) dis[i] = inf;
//		bfs(u, v);
//		ans += dis[v];
		cout << ans << '\n';
	}
}
/*
0 2 5 20 2 
4 1 9 2 5 
3 1 5 2 7 4 6 
3 2 3 3 4 5 7 
1 3 
1 2 
*/
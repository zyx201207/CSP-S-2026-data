#include<bits/stdc++.h>
using namespace std;
const int N = 505;
const int M = 500005;
int c, n, m, d, q;
int w[M];
bool vis[M + N];
long long dis[M + N];
struct node{
	int u;
	long long dis;
};
struct edge{
	int v, w;
};
long long dis_s[N][N];
vector<edge> dlc[M];
vector<int> mly[N + M];
priority_queue<node, vector<node>, greater<node>>pq;
bool operator>(const node &a, const node &b){return a.dis > b.dis;}
vector<edge> g[M + N];
void di(int s){
	dis[s] = 0;
	pq.push({s, 0});
	while(!pq.empty()){
		node last = pq.top();
		pq.pop();
		if(vis[last.u] == 1)continue;
		vis[last.u] = 1;
		for(auto now : g[last.u]){
			if(dis[now.v] > last.dis + now.w){
				dis[now.v] = last.dis + now.w;
				pq.push({now.v, dis[now.v]});
			}
		}
	}
}
void bfs(int s){
	long long cntot = 0;
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int last = q.front();
		q.pop();
		if(vis[last] == 1)continue;
		vis[last] = 1;
		for(auto now : mly[last]){
			if(dis[now] > dis[last] + 1){
				dis[now] = dis[last] + 1;
				q.push(now);
			}
			cntot++;
		}
	}
	cout << "              " << cntot << "\n";
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++)cin >> w[i];
	int tot = m;
	long long ttt = 0;
	for(int i = 1; i <= n; i ++){
		int k;
		cin >> k;
		tot++;
		for(int j = 1; j <= k; j ++){
			int a, t;
			cin >> a >> t;
			ttt = t;
			g[tot].push_back({a, t});
			g[a].push_back({tot, t});
			dlc[a].push_back({i, t});
			mly[tot].push_back(a);
			mly[a].push_back(tot);
			
		}
	}
	if(c >= 12 && c <= 19){
		for(int i = m + 1; i <= tot; i ++){
			for(int j = 1; j <= tot; j ++){
				vis[j] = 0;
				dis[j] = 1e18;
			}
			bfs(i);
			for(int j = m; j <= tot; j ++){
				dis_s[i - m][j - m] = dis[j];
				//cout << dis[j] << " ";
			}
		}
		for(int i = 1; i <= q; i ++){
			int x, y;
			cin >> x >> y;
			long long ans = 1e18;
			for(auto zxy : dlc[x]){
				for(auto syz : dlc[y]){
					ans = min(ans, w[x] + w[y] + zxy.w + syz.w + 1ll * dis_s[zxy.v][syz.v] * ttt);
				}
			}
			cout << ans << "\n";
		}
	}
	else {
		for(int i = m + 1; i <= tot; i ++){
			for(int j = 1; j <= tot; j ++){
				vis[j] = 0;
				dis[j] = 1e18;
			}
			di(i);
			for(int j = m; j <= tot; j ++){
				dis_s[i - m][j - m] = dis[j];
			}
		}
		for(int i = 1; i <= q; i ++){
			int x, y;
			cin >> x >> y;
			long long ans = 1e18;
			for(auto zxy : dlc[x]){
				for(auto syz : dlc[y]){
					ans = min(ans, w[x] + w[y] + zxy.w + syz.w + dis_s[zxy.v][syz.v]);
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
} 

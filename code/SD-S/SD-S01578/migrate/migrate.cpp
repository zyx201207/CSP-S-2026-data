#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(I, A, B) for(int I = (A); I <= (B); I++)
#define den(I, A, B) for(int I = (A); I >= (B); I--)
#define int long long
#define pii pair<int, int> 
#define fr first
#define sc second
const int INF = 0x3f3f3f3f3f3f3f3f;
/*
对这个图跑最短路计数 很显然是 n ^ 2 log n 的，能获得 40 pts

*/
const int N = 5005;
int x[N];
int dis[N][N];
int cnt[N][N];
vector<int> g[N];
int n, d;
void clearer(){
	rep(i, 1, n) rep(j, 1, n) dis[i][j] = INF, cnt[i][j] = 0;
	rep(i, 1, n) g[i].clear();
}
void dij(int s){
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push({0, s});
	dis[s][s] = 0;
	cnt[s][s] = 1;
	while(q.size()){
		auto cur = q.top(); q.pop();
		int u = cur.sc;
//		if(cur.fr >= dis[s][cur.sc]) continue;
		for(int v : g[u]){
			if(dis[s][v] > dis[s][u] + 1){
				
				dis[s][v] = dis[s][u] + 1;
				cnt[s][v] = cnt[s][u];
				q.push({dis[s][v], v});
			}else if(dis[s][v] == dis[s][u] + 1) cnt[s][v] += cnt[s][u];
		}
	}
}
void solve(){
	cin >> n >> d;
	rep(i, 1, n) cin >> x[i];
	rep(i, 1, n) rep(j, 1, n) dis[i][j] = INF, cnt[i][j] = 0;
	rep(i, 1, n){
		for(int j = i - 1; j >= 1 && abs(x[i] - x[j]) <= d; j--) g[i].push_back(j);
		for(int j = i + 1; j <= n && abs(x[i] - x[j]) <= d; j++) g[i].push_back(j);
	}
	rep(i, 1, n) dij(i);
	int ans = 0;
	rep(i, 1, n){
		rep(j, 1, n){
//			cout  << dis[i][j] << " " << cnt[i][j] << endl;
			if(cnt[i][j] == 2) ans++;
		} 
//		cout << "-----------------" << endl;
	}
	ans >>= 1;
	cout << ans << endl;
	clearer();
}
signed main(){
	ios::sync_with_stdio(0);
	cout.tie(0), cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t_;
	cin >> c >> t_;
	while(t_--) solve();
	return 0;
}
/*
fc migrate1.out migrate1.ans
*/

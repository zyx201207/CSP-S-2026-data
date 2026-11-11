#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
const int N = 5e5 + 10;
const int mod = 1e9 + 7;
const ll inf = 1e18;
int c, n, m, d, Q, cnt, k[N], l[N], pos[N];
ll dis[N], fir[N], val[N];
bool p[N], vis[N];
vector<int> rep[N], b[510];
priority_queue<pair<ll, int> > q;
inline ll read(){
	ll x = 0, m = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') m = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * m;
}
inline void write(ll x){
	if(x < 0){
		putchar('-');
		write(-x);
		return;
	}
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
inline void Freopen(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
}
inline ll getdis(int s, int t){
	for(int i = 1; i <= cnt; ++ i) dis[i] = inf, vis[i] = 0;
	for(int i = 0; i < rep[l[s]].size(); ++ i){
		int v = rep[l[s]][i];
		dis[v] = fir[v], q.push(make_pair(-dis[v], v));
	}
	vis[l[s]] = 1;
	while(!q.empty()){
		pair<ll, int> now = q.top(); q.pop();
		int u = now.second, r = pos[u];
		for(int i = 0; i < b[r].size(); ++ i){
			int v = b[r][i];
			if(u == v) continue;
			if(dis[v] > dis[u] + fir[v]){
				dis[v] = dis[u] + fir[v];
				q.push(make_pair(-dis[v], v));
			}
		}
		if(vis[l[u]]) continue;
		vis[l[u]] = 1;
		for(int i = 0; i < rep[l[u]].size(); ++ i){
			int v = rep[l[u]][i];
			if(u == v) continue;
			if(dis[v] > dis[u] + fir[v]){
				dis[v] = dis[u] + fir[v];
				q.push(make_pair(-dis[v], v));
			}
		}
	}
	ll ans = inf;
	for(int i = 0; i < rep[l[t]].size(); ++ i) ans = min(ans, dis[rep[l[t]][i]]);
	return ans;
}
inline void solve(){
	c = read(), n = read(), m = read(), d = read(), Q = read(), cnt = m;
	for(int i = 1; i <= m; ++ i) val[i] = read(), l[i] = i, rep[i].push_back(i);
	for(int i = 1; i <= n; ++ i){
		k[i] = read();
		for(int j = 0; j < k[i]; ++ j){
			int v = read(), w = read();
			if(p[v]) rep[v].push_back(++ cnt), l[cnt] = v, v = cnt;
			else p[v] = 1;
			fir[v] = w, b[i].push_back(v), pos[v] = i;
		}
	}
	while(Q --){
		int x = read(), y = read();
		write(getdis(x, y) + val[x] + val[y]), putchar('\n');
	}
}
signed main(){
	Freopen();
	int T = 1;
//	T = read();
	while(T --) solve();
	return 0;
}


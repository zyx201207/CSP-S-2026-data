#include <bits/stdc++.h>
using namespace std;
struct node {
	int l;
	int nxt;
};
int c , n , m , d , q;
int k_t[500005] , k[505] , a[505][50005] , t[505][50005];
vector <node> e[500005];
int dd[500005] , out = 0;
bool vis[500005];
void dij(int s , int ttt){
	for (int i = 1 ; i <= m ; i ++) {
		vis[i] = 0;
		dd[i] = 1e9;
	}
	priority_queue <pair<int , pair<int , int> > > p;
	for (int i = 0 ; i < e[s].size() ; i ++) {
		p.push({-t[e[s][i].l][s] , {e[s][i].l , s}});
	}
	while(!p.empty()) {
		int u = p.top().second.second;
		int now = p.top().second.first;
		int need_u = -p.top().first;
		p.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = 0 ; i < e[u].size() ; i ++) {
			int v = e[u][i].nxt;
			int ned = e[u][i].l;
			if (v == ttt) need_u += t[ned][v];
			if (ned == now) {
				if (dd[v] > need_u) {
					dd[v] = need_u;
					p.push({-dd[v] , {ned , v}});
				}
			}
			else {
				int ti = t[now][u] + t[ned][u];
				if (dd[v] > need_u + ti) {
					dd[v] = need_u + ti;
					p.push({-dd[v] , {ned , v}});
				}
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1 ; i <= m ; i ++) {
		cin >> k_t[i]; 
	}
	for (int i = 1 ; i <= n ; i ++) {
		cin >> k[i];
		for (int j = 1 ; j <= k[i] ; j ++) {
			cin >> a[i][j];
			int tim;
			cin >> tim;
			t[i][a[i][j]] = tim;
			if (j > 1){
				e[a[i][j - 1]].push_back({i , a[i][j]});
				e[a[i][j]].push_back({i , a[i][j - 1]});
			} 
		}
	}
	for (int i = 1 ; i <= q ; i ++) {
		int x , xx;
		cin >> x >> xx;
		dij(x , xx);
		cout << dd[xx] + k_t[x] + k_t[xx] << endl;
	}
	return 0;
}


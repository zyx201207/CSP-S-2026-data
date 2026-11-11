#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6 + 5;

const int M = 5e3 + 5;

int C,T,n,d,a[N],dis[M][M],cnt[M][M];

vector<int> e[N];

void bfs(int s) {
	queue<pair<int,int> > q;
	q.push({s,0});
	for(int i = 1;i<=n;i++) dis[s][i] = LONG_LONG_MAX,cnt[s][i] = 0;
	while(!q.empty()) {
		int u = q.front().first,t = q.front().second;
		q.pop();
		if(t > dis[s][u]) continue;
		if(t == dis[s][u]) cnt[s][u]++;
		if(t < dis[s][u]) {
			dis[s][u] = t;
			cnt[s][u] = 1;
		}
		for(auto v : e[u]) q.push({v,t+1});
	}
}

void solve() {
	cin >> n >> d;
	for(int i = 1;i<=n;i++) cin >> a[i];
	for(int i = 1;i<=n;i++) e[i].clear();
	for(int i = 1;i<=n;i++) {
		for(int j = i+1;j<=n;j++) {
			int dist = a[j] - a[i];
			if(dist <= d) e[i].push_back(j);
		}
	}
	for(int i = 1;i<=n;i++) bfs(i);
	int ans = 0;
	for(int i = 1;i<=n;i++) for(int j = i+1;j<=n;j++) ans += (cnt[i][j] == 2);
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> C >> T;
	while(T--) solve();
	return 0;
}

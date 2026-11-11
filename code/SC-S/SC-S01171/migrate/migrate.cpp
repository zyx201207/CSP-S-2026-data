#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 5;
using namespace std;
int c, t, n, d, x[100005];
vector<int> e[100005];
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int dis[N];
bool vis[N];
typedef pair<int, int> P;
int dis2[N], cnt[N];
bool vis2[N];
int dijk2(int st) {
	fill(dis2 + 1, dis2 + 1 + n, 0x3f3f3f3f3f3f3f3f);
	fill(vis2 + 1, vis2 + 1 + n, 0);
	fill(cnt + 1, cnt + 1 + n, 0);
	queue<int> q2;
	dis2[st] = 0;
	vis[st] = 1;
	q2.push(st);
	int s = 0;
	while(!q2.empty()) {
		int f2 = q2.front();
		q2.pop();
		vis2[f2] = 0;
		for(int i : e[f2]) {
			if(dis2[i] >= dis2[f2] + 1) {
				dis2[i] = dis2[f2] + 1;
				if(dis2[i] == dis[i]) cnt[i]++;
				q2.push(i);
				vis[i] = 1;
			}
		}
	}
	for(int i = st + 1; i <= n; i++) if(cnt[i] == 2) s++;
	return s;
}
int dijk(int st) {
	fill(dis + 1, dis + 1 + n, 0x3f3f3f3f3f3f3f3f);
	fill(vis + 1, vis + 1 + n, 0);
	priority_queue<P, vector<P>, greater<P> > q;
	dis[st] = 0;
	q.push({0, st});
	while(!q.empty()) {
		int ff = q.top().second;
		q.pop();
		if(vis[ff]) continue;
		vis[ff] = 1;
		for(int i : e[ff]) {
			if(dis[i] > dis[ff] + 1) {
				dis[i] = dis[ff] + 1;
				q.push({dis[i], i});
			}
		}
	}
	return dijk2(st);
}
void solve() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) x[i] = read(), e[i].clear();
	sort(x + 1, x + 1 + n);
	if(c == 11 || c == 12) {
		int delta = x[2] - x[1];
		if(delta > d) {cout << 0;puts("");}
		else {
			int mm = d / delta;
			int ans = 0;
			ans = (n - mm) * (n - mm - 1) / 2;
//			for(int i = 1; i <= n; i++) {
//				ans += (n - i - mm);
//			}
			cout << ans;
			puts("");
		}
	}
	else {
		for(int i = 1; i < n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(x[j] - x[i] <= d) e[i].push_back(j);
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			ans += dijk(i);
		}
		cout << ans;
		puts("");
	}
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		solve();
	}
	return 0;
}
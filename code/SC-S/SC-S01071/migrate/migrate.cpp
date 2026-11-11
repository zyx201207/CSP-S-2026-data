#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i ++ )
#define per(i, l, r) for(int i = (l); i >= (r); i -- )
#define frein(s) freopen(s, "r", stdin)
#define freout(s) freopen(s, "w", stdout)
#define int long long
#define endl '\n'
using namespace std;

const int N = 2e6 + 5;
int c, T, n, d, x[N], cnt[5005], dis[5005], rp[N];
vector<int> g[5005], vt;

void bfs(int s) {
	queue<pair<int, int> > q;
	memset(dis, -1, sizeof dis);
	memset(cnt, 0, sizeof cnt);
	dis[s] = 0;
	cnt[s] = 1;
	q.emplace(0, s);
	while(!q.empty()) {
		int u = q.front().second;
		q.pop();
		for(auto v : g[u]) {
			if(dis[v] == -1) {
				cnt[v] = cnt[u];
				dis[v] = dis[u] + 1;
				q.emplace(dis[v], v);
			} else if(dis[v] == dis[u] + 1) {
				cnt[v] += cnt[u];
				if(cnt[v] > 3) cnt[v] = 3;
			}
		}
	}
}

void print() {
	rep(i, 1, n) for(auto v : g[i]) {
		cout << i << "->" << v << endl;
	}
}

void solve1() {
	rep(i, 1, n) g[i].clear(); 
	rep(i, 1, n) {
		rep(j, 1, n) {
			if(j == i) continue;
			if(abs(x[i] - x[j]) <= d) g[i].push_back(j);
		}
	}
	int ans = 0;
	rep(i, 1, n) {
		bfs(i);
		rep(j, 1, n) {
			if(cnt[j] == 2) ans ++ ;
		}
	}
	cout << ans / 2 << endl;
}

signed main() {
	frein("migrate.in"), freout("migrate.out");
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while(T -- ) {
		cin >> n >> d;
		rep(i, 1, n) cin >> x[i];
		if(c <= 10) solve1();
		else if(11 <= c && c <= 12) {
			if(n == 1) {
				cout << 0 << endl;
				continue;
			}
			int k = x[2] - x[1], p = d / k;
			if(p == 0 || p == 1) {
				cout << 0 << endl;
				continue;
			}
			p = p * 2 - 1;
			cout << max(0ll, n - p) << endl;
		} else {
			vt.clear();
			rep(i, 1, n) {
				int l = i, r = n, mid;
				while(l <= r) {
					mid = l + r >> 1;
					if(x[mid] - x[i] <= d) rp[i] = mid, l = mid + 1;
					else r = mid - 1;
				}
			}
			rep(i, 1, n) vt.push_back(rp[rp[i]]);
			sort(vt.begin(), vt.end());
			vt.erase(unique(vt.begin(), vt.end()), vt.end());
			cout << vt.size() << endl;
		}
	}
	return 0;
}
//code by wsy_I.luogu uid: 1152799
/*
一个可以到处乱飞的岛屿有什么用。
哦，不一定在区间中飞！路径长度必然是1/2。
如果是1，那么肯定不合法；2的话，就是考察区间中跳过去是不是唯一的。
对于每一个左端点处理能够两步跳到的右端点。只有第一个有贡献，也就是去重。 
k步到位这个怎么搞。感觉不好搞。 
300直接建图每个点开始 bfs。 
*/
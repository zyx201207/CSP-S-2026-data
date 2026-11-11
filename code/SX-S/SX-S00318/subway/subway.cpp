#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int w[N], t[N][505], a[N][N], k[N];

struct node {
	int u, d;
};
vector<node> v[100005];
//bool b[505], bb[100005];
int vis[505], dis[505];
int s[500005];

struct f {
	bool p;
	int h;
} b[N];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j];
			cin >> t[i][a[i][j]];
//			if (j > 1) {
//				if (b[a[j]]) {
//					for (int l = 1; l <= n; l++) {
//						if (bb[a[j] + (l - 1) * m] == 1) {
//							v[a[j] + (l - 1)*m].push_back({a[j] + (i - 1)*m, t[i][a[j]] + t[l][a[j]]});
//							v[a[j] + (i - 1)*m].push_back({a[j] + (l - 1)*m, t[i][a[j]] + t[l][a[j]]});
//						}
//					}
//				}
//				v[a[j] + (i - 1)*m].push_back({a[j - 1] + (i - 1)*m, 0});
//				v[a[j - 1] + (i - 1)*m].push_back({a[j] + (i - 1)*m, 0});
//
//				bb[a[j] + (i - 1)*m] = 1;
//				bb[a[j - 1] + (i - 1)*m] = 1;
//			}
		}
	}
	int l = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++) {
			if (b[a[i][j]].p == 1) {
				l++;
				s[l] = t[i][a[i][j]] + t[b[a[i][j]].h][a[i][j]];
			}
			b[a[i][j]].p = 1;
			b[a[i][j]].h = i;
		}
	}
	sort(s + 1, s + l + 1, cmp);
	while (q--) {
		//priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
		int x, y;
		cin >> x >> y;
		long long ans = 0;
		ans += w[x] + t[1][x] + w[y] + t[2][y];
		ans += s[1];
		cout << ans << endl;
//		memset(dis,0x3f,sizeof(dis));
//		memset(vis,0,sizeof(vis));
//		dis[x]=0;
//		while(!Q.empty()){
//			if(vis[])
//
//			for(int i=0;i<v[].size();i++){
//				if(dis[v[][i].u]>dis[]+)
//			}
//		}

	}
	return 0;
}
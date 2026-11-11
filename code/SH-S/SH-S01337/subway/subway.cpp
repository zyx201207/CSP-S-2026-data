#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 5;
int c , n , m , D , q , w[M] , k[505] , x , y;
long long dis[1005][1005] , d[1005][1005];
vector <int> a[505];
vector <long long> t[505];
vector <pair <int , long long> > g[1005];
bool vis[1005];
void dijkstra (int s) {
	for (int i = 1; i <= 1000; i++) d[s][i] = 1e18;
	d[s][s] = 0;
	priority_queue <pair <int , int> , vector<pair <int , int> > , greater <pair <int , int> > > q;
	q.push(make_pair (0 , s));
	memset (vis , 0 , sizeof (vis));
	while (!q.empty ()) {
		int x = q.top ().second;
		q.pop ();
		if (vis[x]) continue;
		vis[x] = 1;
		for (int i = 0; i <g[x].size (); i++) {
			if (d[s][g[x][i].first] > d[s][x] + g[x][i].second) {
				d[s][g[x][i].first] = d[s][x] + g[x][i].second;
				q.push (make_pair (d[s][g[x][i].first] , g[x][i].first));
				//cout << s << " " << x << " " << g[x][i].second << " " << d[s][g[x][i].second] << "\n";
			}
		}
	}
}
int main () {
	freopen ("subway.in" , "r" , stdin);
	freopen ("subway.out" , "w" , stdout);
	ios::sync_with_stdio (false) , cin.tie (0) , cout.tie (0);
	cin >> c >> n >> m >> D >> q;
		for (int i = 1; i <= m; i++) cin >> w[i];
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) dis[i][j] = 3e9;
		}
		for (int i = 1; i <= n; i++) {
			cin >> k[i];
			for (int j = 1; j <= k[i]; j++) {
				int x;
				cin >> x;
				a[i].push_back (x);
				cin >> x;
				t[i].push_back (x);
			}
			for (int j = 0; j < k[i]; j++) {
				for (int l = j + 1; l < k[i]; l++) {
					dis[a[i][j]][a[i][l]] = min (dis[a[i][j]][a[i][l]] , t[i][j] + t[i][l]);
					dis[a[i][l]][a[i][j]] = min (dis[a[i][l]][a[i][j]] , t[i][j] + t[i][l]);
				}
			}
		}
	if (c <= 8) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				for (int k = 1; k <= m; k++) {
					if (i == j) continue;
					dis[i][j] = min (dis[i][j] , dis[i][k] + dis[k][j]);
				}
			}
		}
		while (q--) {
			cin >> x >> y;
			cout << dis[x][y] + w[x] + w[y] << "\n";
		}
	} else {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				if (dis[i][j] != 3e9) {
					g[i].push_back (make_pair (j , dis[i][j]));
					g[j].push_back (make_pair (i , dis[i][j]));
				}
			}
		}
		for (int i = 1;i <= m; i++) dijkstra (i);
		while (q--) {
			cin >> x >> y;
			cout << d[x][y] + w[x] + w[y] << "\n"; 
		}
	}
	return 0;
}

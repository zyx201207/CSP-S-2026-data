#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define LL long long
#define int long long
using namespace std;

const int N = 510,  M = 5e5 + 10;
const LL INF = 1e17;
int k[N], c, n, m, d, q, w[M];
LL dis[N][N];
int tot[M];

vector<pair<int, int>> edge[M];

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	fast;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			dis[i][j] = ((i == j)? 0: INF);
		}
	}
	
	for (int i = 1; i <= n; i++){
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++){
			int a, t;
			cin >> a >> t;
			edge[a].push_back(make_pair(i, t));
//			if (a == 3 && i == 2){
//				cout << t << '\n';
//			}
			tot[a] ++;
		}
	}
	
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= tot[i]; j++){
			for (int l = 1; l <= tot[i]; l++){
				if (j == l) continue;
				int u = edge[i][j - 1].first, v = edge[i][l - 1].first;
				int val1 = edge[i][j - 1].second, val2 = edge[i][l - 1].second;
				dis[u][v] = min(dis[u][v], val1 + val2);
			}
		}
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			dis[i][j] = dis[j][i] = min(dis[i][j], dis[j][i]);
		}
	}
	
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	
	while (q --){
		int x, y;
		cin >> x >> y;
		LL ans = INF;
		for (int i = 1; i <= tot[x]; i++){
			for (int j = 1; j <= tot[y]; j++){
				int u = edge[x][i - 1].first, v = edge[y][j - 1].first;
				int val1 = edge[x][i - 1].second, val2 = edge[y][j - 1].second;
//				cout << u << " " << v << " " << val1 << " " << val2 << '\n';
				ans = min(ans, dis[u][v] + val1 + val2 + w[x] + w[y]);
			}
		}
		cout << ans << '\n';
//		cout << '\n';
	}
	
}
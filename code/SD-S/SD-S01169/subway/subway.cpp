#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>

//#define int long long

using namespace std;

const int N = 503, M = 5e5 + 3, LL_MAX = 0x3f3f3f3f3f3f3f3f;

struct stop{
	public:
		vector<int> ways;
} stops[M];

int c, n, m, d, Q;
int w[M];
long long Map[N][N];
int way_to_stop[N][M];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	memset(Map, 0x3f, sizeof Map);
	
	cin >> c >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	
	for (int i = 1; i <= n; i ++) {
		int k;
		cin >> k;
		
		for (int j = 1; j <= k; j ++) {
			int id, dis;
			cin >> id >> dis;
			stops[id].ways.push_back(i);
			way_to_stop[i][id] = dis;
//			cout << "FUCK!" << id << ' ' << dis << endl;
		}
//		cout << "FUCK!" << endl;
	}
	
	// build
	for (int k = 1; k <= m; k ++) {
		auto t = stops[k].ways;
//		if (k == 1) for (auto it : t) cout << it << endl;
		for (int i = 0; i < t.size(); i ++) {
			for (int j = 0; j < t.size(); j ++) {
				if (t[i] != t[j]) Map[t[i]][t[j]] = min(Map[t[i]][t[j]], (long long)(way_to_stop[t[i]][k]) + (long long)(way_to_stop[t[j]][k]));
				else Map[t[i]][t[j]] = 0ll;
//				cout << "FUCK!" << endl;
//				if (Map[t[i]][t[j]] == LL_MAX) Map[t[i]][t[j]] = 0;
			}
		}
	}
	
	// floyd
//	for (int i = 1; i <= n; i ++) {
//		for (int j = 1; j <= n; j ++) {
//			cout << Map[i][j] << ' ';
//		}
//		cout << endl;
//	}
	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);
			}
		}
	}
	
	// check ans
//	for (int i = 1; i <= n; i ++) {
//		for (int j = 1; j <= n; j ++) {
//			cout << Map[i][j] << ' ';
//		}
//		cout << endl;
//	}
	
	for (int k = 0; k < Q; k ++) {
		int x, y;
		cin >> x >> y;
		
		long long ans = LONG_LONG_MAX;
//		auto fir = stops[x].ways, sec = stops[y].ways;
		
//		for (auto it : fir) cout << it << ' ';
//		cout << endl;
//		for (auto it : sec) cout << it << ' ';
//		cout << endl;

//		cout << Map[fir[0]][sec[0]] + w[x] + w[y] + way_to_stop[1][1] + way_to_stop[2][3] << endl;
		
		for (int i = 0; i < stops[x].ways.size(); i ++) {
			for (int j = 0; j < stops[y].ways.size(); j ++) {
				ans = min(ans, Map[stops[x].ways[i]][stops[y].ways[j]] + w[x] + w[y] + way_to_stop[stops[x].ways[i]][x] + way_to_stop[stops[y].ways[j]][y]);
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
--------------
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

God blesses me pass this problem plz.
*/

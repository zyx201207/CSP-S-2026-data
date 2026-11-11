#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int M = 305;
using ll = long long;
int c, n, m, d, q;
int w[M];
int a[N][M], t[N][M];
vector <pair <int, int>> PR[N];
int K[N];
struct node{
	int at, floor, time;
	const bool operator <(node st){
		return time < st.time;
	} 
};

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 

	cin >> c >> n >> m >> d >> q; q=1; 
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1, k; i <= n; i ++){
		cin >> k;
		K[i] = k;
		for (int j = 0; j < k; j ++){
			cin >> a[i][j] >> t[i][j];
			PR[a[i][j]].push_back(make_pair(i, j));
		}
	} 
	
	while (q --){
		int x, y; cin >> x >> y;
		map <pair <int, int>, int> vis;
		queue <node> pq;
		for (pair <int, int> P : PR[x]){
			pq.push({
				x,
				P.first,
				w[x] + t[P.first][P.second] 
			});
		}
		int ans = 0x3f3f3f3f;
		while (!pq.empty()){
			node frt = pq.front(); pq.pop();
			if (frt.at == y){
				int idx;
				for (auto P : PR[frt.at]){
					if (P.first == frt.floor){
						idx = P.second; break;
					}
				}
				ans = min(ans, frt.time + w[y] + t[frt.floor][idx]); continue;
			}
			if (vis.find(make_pair(frt.at, frt.floor)) == vis.end()) vis[make_pair(frt.at, frt.floor)] = frt.time;
			else if (vis[make_pair(frt.at, frt.floor)] <= frt.time) continue;
			cout << frt.at << ' ' << frt.floor << ' ' << frt.time << '\n';
			for (int i = 1; i < K[i]; i ++){
				int P = a[frt.floor][i];
				pq.push({
					P,
					frt.floor,
					frt.time
				});
			}
			int idx;
			for (auto P : PR[frt.at]){
				if (P.first == frt.floor){
					idx = P.second; break;
				}
			}
			for (auto P : PR[frt.at]){
				if (P.first == frt.floor) continue; 
				pq.push({
					frt.at,
					P.first,
					frt.time + t[frt.floor][idx] + t[P.first][P.second]
				});
			}
		}
		cout << ans << '\n';
	}

	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 5005;
bool vis[MAXN];
long long x[MAXN];
int dist[MAXN][MAXN], cnt[MAXN][MAXN], sum[MAXN];
vector<int> graph[MAXN], rev[MAXN];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
		while (t--){
			int n;
			long long d;
			cin >> n >> d;
			for (int i = 1; i <= n; ++i){
				cin >> x[i];
				graph[i].clear();
				rev[i].clear();
			}
			for (int i = 1; i <= n - 1; ++i){
				for (int j = i + 1; j <= n; ++j){
					if (x[j] - x[i] <= d){
						graph[i].push_back(j);
						rev[j].push_back(i);
					}
				}
			}
			for (int i = 1; i <= n; ++i)
				sort(rev[i].begin(), rev[i].end());
			for (int i = 1; i <= n; ++i){
				for (int j = 1; j <= n; ++j){
					if (i == j){
						dist[i][j] = 0;
						cnt[i][j] = 1;
					}
					else{
						dist[i][j] = INF;
						cnt[i][j] = 0;
					}
				}
			}
			for (int i = 1; i <= n; ++i){
				for (int j = 1; j <= n; ++j)
					vis[j] = false;
				queue<int> q;
				q.push(i);
				while (!q.empty()){
					int u = q.front();
					q.pop(); 
					if (vis[u])
						continue;
					vis[u] = true;
					for (int v : graph[u]){
						if (dist[i][u] + 1 < dist[i][v]){
							dist[i][v] = dist[i][u] + 1;
							q.push(v);
						}
					}
				}
				for (int j = 1; j <= n; ++j)
					sum[j] = 0;
				for (int j = i + 1; j <= n; ++j){
					for (int y : rev[j]){
						if (dist[i][y] + 1 == dist[i][j])
							cnt[i][j] += cnt[i][y];
					}
				}
			}
			int ans = 0;
			for (int i = 1; i <= n - 1; ++i){
				for (int j = i + 1; j <= n; ++j){
					if (cnt[i][j] == 2)
						++ans;
				}
			}
			cout << ans << '\n';
		}		
}

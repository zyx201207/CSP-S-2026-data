#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 510;
const int M = 2e4 + 10;

int c, n, m, d, q;
int w[M]; // 表示地铁口到展厅 i的时间 
int k[N]; // 第i条地铁经过地铁站数
vector<int> a[N]; // 第i条线路经过的第j个地铁站
vector<int> t[N]; // 第a[i][j]个地铁站站厅走到第i条线路的站台的时间 

vector<pair<int, int>> p[M]; // p[i]表示站厅i的所有线路，包含{线路标号，第几个车站}

int di[N][N]; // 站厅和站厅的距离 

queue<pair<int, int>> pq;
bool vis[N];
ll dis[N];

void route(int x, int y){
	memset(dis, 0x3f, sizeof(dis));
	pq.push({0, x});
	vis[x] = 1;
	dis[x] = 0;
	while (!pq.empty()){
		pair<int, int> u = pq.front(); pq.pop();
		int from = u.second, len = u.first;
		if (vis[from]) continue;
		for (int i = 0; i < p[from].size(); i++){
			int line = p[from][i].first;
			for (int j = 1; j <= k[line]; j++){
				if (j == p[from][i].second) continue;
				if (dis[a[line][j]] > dis[from] + t[line][p[from][i].second] + t[line][j]){
					dis[a[line][j]] = dis[from] + t[line][p[from][i].second] + t[line][j];
					pq.push({t[line][p[from][i].second] + t[line][j], a[line][j]});
				}
				
			}
		}
	}
	cout << dis[y] << endl;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	
	for (int i = 1; i <= n; i++){
		cin >> k[i];
		a[i].push_back(0); t[i].push_back(0);
		for (int j = 1; j <= k[i]; j++){
			int a_, t_; cin >> a_ >> t_;
			a[i].push_back(a_); t[i].push_back(t_);
			p[a_].push_back({i, j});
		}
	}
	
	
	while (q--){
		memset(vis, 0, sizeof(vis));
		memset(dis, 0, sizeof(dis));
		int x, y; cin >> x >> y;
		route(x, y);
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
} 

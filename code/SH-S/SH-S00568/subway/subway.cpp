#include<bits/stdc++.h>
#define io ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int N = 510;
const int M = 5e5 + 10;
const int Q = 1e5 + 10;
int w[M];
int k[N];
vector<int> a[N];
vector<long long> t[N];
int x[Q], y[Q];
vector<pair<int, long long> > cnct[M];
long long dis[N][N];
vector<pair<int, long long> > g[N];
long long res[N][N];
long long calc(int x, int y){
	if(x == y) return 0;
	if(x > y) swap(x, y);
	return dis[x][y];
}
void bfs(int st){
	queue<pair<int, long long> >q;
	q.push({st, 0});
	while(q.size()){
		auto u = q.front();
		q.pop();
		res[st][u.first] = min(res[st][u.first], u.second);
		for(int i = 0; i < g[u.first].size(); i ++){
			int xx = g[u.first][i].first;
			long long newdis = u.second + g[u.first][i].second;
			if(newdis >= res[st][xx]) continue;
			q.push({xx, newdis});
		}
	}
	return;
}
int main(){
	io;
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dis, 0x3f, sizeof dis);
	memset(res, 0x3f, sizeof res);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i ++){
		cin >> k[i];
		for(int j = 0; j < k[i]; j ++){
			long long x, y;
			cin >> x >> y;
			a[i].push_back(x);
			t[i].push_back(y);
			cnct[x].push_back({i, y});
		}
	}
	for(int i = 1; i <= q; i ++){
		cin >> x[i] >> y[i];
	}
	
	for(int i = 1; i < m; i ++){
		for(int j = 0; j < cnct[i].size(); j ++){
			for(int k = j + 1; k < cnct[i].size(); k ++){
				int x = cnct[i][j].first;
				int y = cnct[i][k].first;
				if(x > y) swap(x, y);
				dis[x][y] = min(dis[x][y], cnct[i][j].second + cnct[i][k].second);
			}
		}
	}
	for(int i = 1; i <= n; i ++){
		for(int j = i + 1; j <= n; j ++){
			g[i].push_back({j, dis[i][j]});
			g[j].push_back({i, dis[i][j]});
		}
	}
	for(int i = 1; i <= n; i ++){
		bfs(i);
	}
	for(int i = 1; i <= q; i ++){
		unsigned long long ans = -1;
		for(int j = 0; j < cnct[x[i]].size(); j ++){
			for(int k = 0; k < cnct[y[i]].size(); k ++){
				ans = min(ans, (unsigned long long)w[x[i]] + 
								cnct[x[i]][j].second + 
								res[cnct[x[i]][j].first][cnct[y[i]][k].first] + 
								cnct[y[i]][k].second + 
								w[y[i]]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

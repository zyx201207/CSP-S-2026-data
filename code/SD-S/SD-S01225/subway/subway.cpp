#include <cstdint>
#include <fstream>
#include <limits>
#include <vector>

constexpr int64_t Inf = std::numeric_limits<int64_t>::max() / 7; 

int main() {
	using namespace std;
	ifstream cin("subway.in");
	ofstream cout("subway.out");
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	auto tzt = new int64_t[m];
	for(int i = 0; i < m; i++)
		cin >> tzt[i];
		
	auto adj_path = new vector<pair<int, int64_t>>[m];
	auto path = new vector<pair<int, int64_t>>[n];
	for(int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		path[i].resize(k);
		for(auto& j : path[i])
		{
			cin >> j.first >> j.second;
			--j.first;
			adj_path[j.first].emplace_back(i, j.second);
		} 
	}
	
	vector<vector<int64_t>> dis(n, vector<int64_t>(n, Inf));
	for(int i = 0; i < n; i++)
		dis[i][i] = 0;
	auto choose_min = [] (int64_t& to, int64_t val) {
		if(val < to)
			to = val;
	};
	for(int i = 0; i < m; i++)
		for(int j = 0; j < adj_path[i].size(); j++)
			for(int k = 0; k < adj_path[i].size(); k++)
				if(j != k)
				{
					choose_min(dis[adj_path[i][j].first][adj_path[i][k].first],
						adj_path[i][j].second + adj_path[i][k].second);
				} 
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				choose_min(dis[i][j], dis[i][k] + dis[k][j]);
	
	auto adj_vd = new vector<int64_t>[m];
	for(int i = 0; i < m; i++)
	{
		adj_vd[i].assign(n, Inf);
		for(const auto j : adj_path[i])
			for(int k = 0; k < n; k++)
				choose_min(adj_vd[i][k], dis[j.first][k] + j.second);
	}
	
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		int64_t ans = Inf;
		for(auto i : adj_path[y])
			ans = min(ans, adj_vd[x][i.first] + i.second);
		cout << ans + tzt[x] + tzt[y] << '\n';
	}
	delete[] adj_vd;
	delete[] path;
	delete[] adj_path;
	delete[] tzt;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int c, n, m, d, q, station_in[N], subway_station[505][50], plane[N][2];
struct st{
	int station, line;
};
vector<st> e[N];vector<int> go[N];
int trans[N][505];

int solve(int start, int end)
{
	int dis[N], vis[N] = {};
	memset(dis, 0x3f, sizeof(dis));
	queue<pair<int, pair<int, int>> > q;
	for(auto i : go[start])
	{
		q.push({start, {i, trans[start][i]}});
	}
	
	while(q.size())
	{
		auto R = q.front();
		q.pop();
		for(auto i : e[R.first])
		{
			cout << R.first << "->" << i.station << " is line" << i.line << "\n";
			int time = R.second.second;
			if(i.line != R.second.first)
			{
				time += trans[R.first][i.line] + trans[R.first][R.second.first];
				//hcout << trans[R.first][i.line] + trans[R.first][R.second.first] << " ";
			}
			if(time < dis[i.station] - trans[i.station][i.line])
			{
				dis[i.station] = time + trans[i.station][i.line];
				q.push({i.station, {i.line, time}});
			}
		}
	}
	return dis[end];
}

int main()
{
	freopen("subway.in","r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++)
	{
		cin >> station_in[i];
	}
	for(int i = 1; i <= n; i ++)
	{
		int k;
		cin >> k;
		subway_station[i][0] = k;
		for(int j = 1; j <= k * 2; j ++){
			cin >> subway_station[i][j];
		}
			
	}
	for(int i = 1; i <= q; i ++)
	{
		cin >> plane[i][0] >> plane[i][1];
	}
	for(int i = 1; i <= n; i ++)
	{
		go[subway_station[i][1]].push_back(i);
		trans[subway_station[i][1]][i] = subway_station[i][2];
		for(int j = 3; j <= subway_station[i][0]* 2; j += 2)
		{
			e[subway_station[i][j]].push_back({subway_station[i][j - 2], i});
			e[subway_station[i][j - 2]].push_back({subway_station[i][j], i});
			//if(j == 7) cout << "bjgvjvujyfvug";
			go[subway_station[i][j]].push_back(i);
			trans[subway_station[i][j]][i] = subway_station[i][j + 1];
			
		}
	}
	
	
//////////////////////////////////////////////////////////////////////////////////
	
	for(int i = 1; i <= q; i ++)
	{
		cout << solve(plane[i][0], plane[i][1]) + station_in[plane[i][0]] + station_in[plane[i][1]] << '\n';
	}//
	return 0;
}


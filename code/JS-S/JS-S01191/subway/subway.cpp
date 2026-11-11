// JS-S01191
// subway.cpp
// submit_part
// version: 2
// TLE from 3
// ToT

#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005];
vector<int> ba[505];
vector<int> bt[505];
map<int, vector<pair<int, int> > > mp;
map<int, map<int, int> > trans;        // tranlatetime [sline][tline][mintime]
map<int, vector<int> > transline;      // tranlateline [sline][i] (maybe chongfu)
map<int, map<int, int> > statlinepos;
int vis[505];

// id -> line   mp[id][i].first

int calu(int x, int y){
	int ans = INT_MAX;
	for (int i = 1; i <= n; ++i){
		vis[i] = 0;
	}
	/*vector<int> a[505];
	vector<int> t[505];*/
	for (int i = 1; i <= n; ++i){
		for (int j = 0; j < ba[i].size(); ++j){
			if (mp[ba[i][j]].size() > 1){
				for (int k = 0; k < mp[ba[i][j]].size(); ++k){
					transline[i].push_back(mp[ba[i][j]][k].first);
					if (trans[i][mp[ba[i][j]][k].first]){
						int spendtime = bt[i][j] + bt[mp[ba[i][j]][k].first][statlinepos[ba[i][j]][mp[ba[i][j]][k].first]];
						if (spendtime < trans[i][mp[ba[i][j]][k].first]){
							trans[i][mp[ba[i][j]][k].first] = spendtime;
						}
					} else {
						int spendtime = bt[i][j] + bt[mp[ba[i][j]][k].first][statlinepos[ba[i][j]][mp[ba[i][j]][k].first]];
						trans[i][mp[ba[i][j]][k].first] = spendtime;
					}
				}
			} 
			/*if (mp[ba[i][j]].size() > 1 || ba[i][j] == x || ba[i][j] == y){
				a[i].push_back(ba[i][j]);
				t[i].push_back(bt[i][j]);
			}*/
		}
	}
	
	queue<int> q;
	for (int i = 0; i < mp[x].size(); ++i){
		q.push(mp[x][i].first);
		//printf("%d", mp[x][i].first);
		vis[mp[x][i].first] = w[x] + bt[mp[x][i].first][mp[x][i].second];
	}
	
	while (!q.empty()){
		int now = q.front();q.pop();
		// cout << now << " " << vis[now] << endl;
		for (int i = 0; i < transline[now].size(); ++i){
			int spendtime = vis[now] + trans[now][transline[now][i]];
			if (vis[transline[now][i]] == 0 || vis[transline[now][i]] > spendtime){
				vis[transline[now][i]] = spendtime;
				q.push(transline[now][i]);
			}
			/*int ifgotime;
			if (mp[now][i].second > 0 && mint[a[mp[now][i].first][mp[now][i].second + 1]] > mint[a[mp[now][i].first][mp[now][i].second]]){
				mint[mp[[now][i].first][mp[now][i].second + 1] = mint[ba[now][i].first][mp[now][i].second];
				q.push(mp[now][i].first][mp[now][i].second + 1])
			}*/
		}
	}
	for (int i = 0; i < mp[y].size(); ++i){
		ans = min(ans, vis[mp[y][i].first] + bt[mp[y][i].first][mp[y][i].second]);
	}
	return ans + w[y];
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; ++i){
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; ++i){
		int nown, nowa, nowt;
		scanf("%d", &nown);
		for (int j = 0; j < nown; ++j){
			scanf("%d%d", &nowa, &nowt);
			ba[i].push_back(nowa);
			bt[i].push_back(nowt);
			mp[nowa].push_back({i, j});
			statlinepos[nowa][i] = j;
		}
	}
	for (int i = 1; i <= q; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", calu(x, y));
	}
	
	return 0;
}


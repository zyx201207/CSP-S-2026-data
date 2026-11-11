#include <bits/stdc++.h>
//#define int long long
using namespace std;
priority_queue<pair<long long, pair<bool, int>>, vector<pair<long long, pair<bool, int>>>, greater<pair<long long, pair<bool, int>>>>q1;

vector<pair<int, int>>li[502];
vector<pair<int, int>>st[500002]; //站+时间
int c, n, m, d, q, s, f, ans = 0, la;
int w[500002];
long long dis[500002], disl[502];
bool mark[500002];
bool markl[502];
void hui(int a, int b) {
	cout << dis[b] + w[a] + w[b];
	return ;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int pi, a, t;
		cin >> pi;
		for (int j = 1; j <= pi; j++) {
			cin >> a >> t;
			li[i].push_back(make_pair(a, t));
			st[a].push_back(make_pair(i, t));
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> s >> f;
		if (s == la) {
			hui(s, f);
			continue;
		}
		for (int j = 1; j <= m; j++) {
			dis[j] = INT_MAX;
			mark[j] = 0;
		}
		for (int j = 1; j <= n; j++) {
			disl[j] = INT_MAX;
			markl[j] = 0;
		}
		dis[s] = 0;
		mark[s] = 1;
		for (int j = 0; j < st[s].size(); j++) {
			q1.push(make_pair(st[s][j].second, make_pair(0, st[s][j].first)));
			disl[st[s][j].first] = st[s][j].second;
			//pair<总时间,pair<站1线0,点>>
		}
		while (!q1.empty()) {
			pair<int, pair<int, int>>p = q1.top();
			q1.pop();
			if (p.second.first == 1) {
				if (mark[p.second.second] == 1)
					continue;
				mark[p.second.second] = 1;
			} else {
				if (markl[p.second.second] == 1)
					continue;
				markl[p.second.second] = 1;
			}


			if (p.second.first == 0) {//线->站
				for (int j = 0; j < li[p.second.second].size(); j++) {
					if (p.first + li[p.second.second][j].second < dis[li[p.second.second][j].first]) {
						dis[li[p.second.second][j].first] = p.first + li[p.second.second][j].second;
						q1.push(make_pair(dis[li[p.second.second][j].first], make_pair(1, li[p.second.second][j].first)));
					}
				}
			} else {                  //站->线
				for (int j = 0; j < st[p.second.second].size(); j++) {
					if (p.first + st[p.second.second][j].second < disl[st[p.second.second][j].first]) {
						disl[st[p.second.second][j].first] = p.first + st[p.second.second][j].second;
						q1.push(make_pair(disl[st[p.second.second][j].first], make_pair(0, st[p.second.second][j].first)));
					}
				}
			}
		}
		cout << dis[f] + w[s] + w[f] << '\n';//
		la = s;
	}
//	for (int i = 1; i <= n; i++)
//		cout << disl[i] << " ";
//	for (int i = 1; i <= m; i++) {
//		for (int j = 0; j < st[i].size(); j++) {
//			cout << st[i][j].first << " ";
//		}
//		cout << endl;
//	}
	return 0;
}
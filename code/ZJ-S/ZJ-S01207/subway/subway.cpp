#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector<long long> w(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    struct Line {
        int id;
        vector<int> stations; 
        vector<long long> t; 
    };
    vector<Line> lines(n + 1);
    vector<vector<pair<int, pair<int, long long>>>> station_platforms(m + 1);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        lines[i].id = i;
        lines[i].stations.resize(k);
        lines[i].t.resize(k);
        for (int j = 0; j < k; j++) {
            cin >> lines[i].stations[j] >> lines[i].t[j];
            station_platforms[lines[i].stations[j]].push_back({i, {j, lines[i].t[j]}});
        }
    }
    int total_platforms = 0;

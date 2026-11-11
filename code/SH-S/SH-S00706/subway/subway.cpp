#include <bits/stdc++.h>
using namespace std;

#define INF 1e17
#define pLLi pair<long long, int>
#define piLL pair<int, long long>
#define ll long long

int main() {

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;

	vector<ll> extC(m + 1);
	for (int i = 1; i <= m; i++)
        cin >> extC[i];

    vector<vector<piLL>> r2v(m + 5);
    for (int i = 1; i <= n; i++) {
        int ki; cin >> ki;
        for (int j = 0; j < ki; j++) {
            ll ai, ti;
            cin >> ai >> ti;

            r2v[ai].push_back({i, ti});
        }
    }

    vector<vector<ll>> mat(n + 1, vector<ll>(n + 1, INF));
    for (auto& rp : r2v)
        for (auto& vp1 : rp)
            for (auto& vp2 : rp)
                mat[vp1.first][vp2.first] = mat[vp2.first][vp1.first] = min(mat[vp1.first][vp2.first],
                                                vp1.second + vp2.second);

    vector<vector<piLL>> g(n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (mat[i][j] < INF)
                g[i].push_back({j, mat[i][j]});


    vector<vector<ll>> fDist(n + 1);
    for (int i = 1; i <= n; i++) {
        vector<ll> dist(n + 1, INF);
        priority_queue<pLLi, vector<pLLi>, greater<pLLi>> pq;
        vector<bool> vis(n + 1);
        pq.push({0, i});
        dist[i] = 0;

        while(!pq.empty()) {
            auto u = pq.top();
            pq.pop();
            if (vis[u.second])
                continue;

            for (auto v : g[u.second]) {
                pq.push({v.second, v.first});
                dist[v.first] = min(dist[v.first],
                                    dist[u.second] + v.second);
            }
            vis[u.second] = true;
        }
        fDist[i] = dist;
    }

    for (int i = 1; i <= q; i++) {
        ll x1, y1;
        cin >> x1 >> y1;

        ll mmin = INF;
        for (piLL a : r2v[x1]) {
            for (piLL b : r2v[y1]) {
                ll w = fDist[a.first][b.first];
                mmin = min(mmin, w + a.second + b.second);
            }
        }

        cout << mmin + extC[x1] + extC[y1] << endl;
    }


	return 0;
}

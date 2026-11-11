//T2-subway is st and meaningful
//why is st?
//because C of all of the example is zero, it is boy one zhi star
//and NO one tell me that A->B means B can go to A
//it also waste me 1h
//why is meaningful?
//because of B.
//B is tell me how to li yong n<=500
//When I see it, I kill T2 easily;
#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MAXM = 5e5 + 5;
constexpr int MAXN = 500 + 5;
constexpr int SUBTASKA_MAXN = 1e3 + 5;
constexpr int INF = 1e18;
int c, n, m, d, q;
int dist[MAXN][MAXN];
int w[MAXM], len[MAXM];
vector<int> a[MAXM];
vector<int> t[MAXM];
vector<int> id[MAXM];
vector<tuple<int, int> > belong[MAXM];
vector<tuple<int, int> > E[MAXN];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    for(int i = 0; i < MAXN; i++) {
        for(int j = 0; j < MAXN; j++) {
            dist[i][j] = INF;
        }
    }
    cin >> c >> n >> m >> d >> q;
    for(int i = 1 ; i <= m; i++) {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> len[i];
        a[i].resize(len[i] + 1), t[i].resize(len[i] + 1);
        id[i].resize(len[i] + 1);
        for(int j = 1; j <= len[i]; j++) {
            cin >> a[i][j] >> t[i][j];
            belong[a[i][j]].push_back(make_tuple(i, t[i][j]));
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int x = 0; x < belong[i].size(); x++) {
            for(int y = x + 1; y < belong[i].size(); y++) {
                tuple<int, int> X = belong[i][x];
                tuple<int, int> Y = belong[i][y];
                int u = get<0>(X), v = get<0>(Y);
                int w = get<1>(X) + get<1>(Y);
                E[u].push_back(make_tuple(w, v));
                E[v].push_back(make_tuple(w, u));
            }
        }
    }
    //yu chu li

    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int> > > que;
    for(int i = 1; i <= n; i++) {
        //cout << "i: " << i << endl;
        //cong i chu fa
        dist[i][i] = 0;
        que.push(make_tuple(0, i));
        while(!que.empty()) {
            tuple<int, int> hafsdjhfkldf = que.top();
            que.pop();
            int nnow = get<1>(hafsdjhfkldf);
            int val = get<0>(hafsdjhfkldf);
            if(val > dist[i][nnow]) {
                continue;
            }
            for(tuple<int, int> to : E[nnow]) {
                int new_w = val + get<0>(to);
                if(new_w < dist[i][get<1>(to)]) {
                    dist[i][get<1>(to)] = new_w;
                    que.push(make_tuple(new_w, get<1>(to)));
                }
            }
        }
    }
    //for(int i = 1; i <= n; i++) {
    //    for(int j = 1; j <= n; j++) {
    //        cout << dist[i][j] << ' ';
    //    } cout << endl;
    //}
    for(int T = 1; T <= q; T++) {
        int x, y; cin >> x >> y;
        //zhi jie qu sou
        int result = INF;
        for(int i = 0; i < belong[x].size(); i++) {
            for(int j = 0; j < belong[y].size(); j++) {
                tuple<int, int> X = belong[x][i];
                tuple<int, int> Y = belong[y][j];
                int u = get<0>(X), v = get<0>(Y);
                int w = get<1>(X) + get<1>(Y);
                result = min(result, w + dist[u][v]);
            }
        }
        //cout << x << ' ' << y << endl;
        cout << result + w[x] + w[y] << endl;
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/

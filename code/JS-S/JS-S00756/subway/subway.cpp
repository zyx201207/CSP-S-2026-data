#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 1; i <= n; i++)
using namespace std;
const int N = 5e5 + 10, INF = 9e18;
int c, n, m, d, q;
int dis[510][510];
int w[N];
vector<pair<int,int> > sta[N];
void caldis(int x){
    for(int i = 0; i < sta[x].size(); i++){
        for(int j = 0; j < i; j++){
            int xa = sta[x][i].first, xt = sta[x][i].second;
            int ya = sta[x][j].first, yt = sta[x][j].second;
            dis[xa][ya] = min(dis[xa][ya], xt + yt);
            dis[ya][xa] = dis[xa][ya];
        }
    }
}
void Floyd(){
    rep(k, n){
        rep(i, n){
            rep(j, n){
                if(dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    rep(i, 500){
        rep(j, 500){
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    }
    cin >> c >> n >> m >> d >> q;
    cout << q << ' ';
    rep(i, m) cin >> w[i];
    rep(i, n){
        int k;
        cin >> k;
        rep(j, k){
            int a, t;
            cin >> a >> t;
            sta[a].push_back({i, t});
        }
    }
    rep(i, m){
        caldis(i);
    }
    Floyd();
    while(q--){
        int x, y;
        cin >> x >> y;
        int ans(INF);
        for(int i = 0; i < sta[x].size(); i++){
            for(int j = 0; j < sta[y].size(); j++){
                int xa = sta[x][i].first, xt = sta[x][i].second;
                int ya = sta[y][j].first, yt = sta[y][j].second;
                ans = min(ans, dis[xa][ya] + xt + yt);
            }
        }
        cout << ans + w[x] + w[y] << '\n';
    }
    /*
    rep(i, n){
        rep(j, n){
            cout << dis[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    return 0;
}

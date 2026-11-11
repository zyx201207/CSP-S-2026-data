#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505,M = 5e5 + 5;
const ll Inf = 1e16;
int c,n,m,d,q,ca,ct,x,y;
int w[M],k[N];
pair<int,int> edge[M][21];
ll dis[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= n;j++){
            dis[i][j] = Inf;
        }
    }
    for (int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for (int i = 1;i <= n;i++){
        cin >> k[i];
        for (int j = 1;j <= k[i];j++){
            cin >> ca >> ct;
            edge[ca][++edge[ca][0].first] = make_pair(i,ct);
        }
    }
    for (int i = 1;i <= m;i++){
        for (int j = 1;j < edge[i][0].first;j++){
            for (int k = j + 1;k <= edge[i][0].first;k++){
                int u = edge[i][j].first;
                int v = edge[i][k].first;
                //cout << u << ' ' << v << ':' << (edge[i][j].second + edge[i][k].second) * 1ll << '\n';
                dis[u][v] = min(dis[u][v],(edge[i][j].second + edge[i][k].second) * 1ll);
            }
        }
    }

    for (int k = 1;k <= n;k++){
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= n;j++){
                if (i == j) {dis[i][j] = 0;continue;}
                dis[i][j] = dis[j][i] = min(dis[i][j],dis[i][k] + dis[k][j]);
            }
        }
    }
    while (q--){
        ll ans = Inf;
        cin >> x >> y;
        for (int i = 1;i <= edge[x][0].first;i++){
            for (int j = 1;j <= edge[y][0].first;j++){
                int u = edge[x][i].first,v = edge[y][j].first;
                //cout << u << ' ' << v << ' ' << dis[u][v] << '\n';
                //cout << w[x] << ' ' << w[y] << ' ' << edge[x][i].second << ' ' << edge[y][i].second << '\n';
                ans = min(ans,dis[u][v] + w[x] + w[y] + edge[x][i].second + edge[y][j].second);
                //cout << dis[u][v] + w[x] + w[y] + edge[x][i].second + edge[y][j].second << '\n';
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

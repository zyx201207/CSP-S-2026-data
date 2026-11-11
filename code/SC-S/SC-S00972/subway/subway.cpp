#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 505;
const int M = 5e5 + 15;
const ll inf = 1e18;
int c,n,m,d,q;
int w[M];
vector<int> a[N],t[N];
vector<pair<int,int>> st[M];
ll G[N][N];
void solve(){
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= n;i ++) for(int j = 1;j <= n;j ++)
        G[i][j] = inf;
    for(int i = 1;i <= n;i ++) G[i][i] = 0;
    for(int i = 1;i <= m;i ++)
        cin >> w[i];
    for(int i = 1;i <= n;i ++){
        int k;cin >> k;
        for(int j = 1;j <= k;j ++){
            int x,y;cin >> x >> y;
            a[i].emplace_back(x);
            t[i].emplace_back(y);
            st[x].push_back({i,j - 1});
        }
    }
    for(int i = 1;i <= m;i ++){
        for(int j = 0;j < st[i].size();j ++) for(int k = 1;k < st[i].size();k ++){
            int x = st[i][j].first,y = st[i][k].first;
            int xs = st[i][j].second,ys = st[i][k].second;
            ll Tm = t[x][xs] + t[y][ys];
            // cout << G[x][y] << " " << Tm << '\n';
            G[x][y] = G[y][x] = min(G[x][y],Tm);
            // cout << x << " " << y << " " << G[x][y] << " " << Tm << '\n';
        }
    }
    // for(int i = 1;i <= n;i ++) for(int j = 1;j <= n;j ++)
    //     cout << G[i][j] << " \n"[j == n];
    for(int i = 1;i <= n;i ++) for(int j = 1;j <= n;j ++)
        for(int k = 1;k <= n;k ++){
            G[i][j] = min(G[i][j],G[i][k] + G[k][j]);
        }
    while(q --){
        int S,T;cin >> S >> T;
        ll minn = inf;
        // cout << S << " " << T << '\n';
        for(int i = 0;i < st[S].size();i ++) for(int j = 0;j < st[T].size();j ++){
            int x = st[S][i].first,xs = st[S][i].second;
            int y = st[T][j].first,ys = st[T][j].second;
            minn = min(minn,G[x][y] + t[x][xs] + t[y][ys] + w[S] + w[T]);
            // cout << x << " " << y << " " << minn << '\n';
        }
        cout << minn << '\n';
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while(T --) solve();
    return 0;
}
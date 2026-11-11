#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
#define fi first
#define se second

const i64 inf=(1LL)<<60;
const int N=410;
int c, n, m, d, q;
int w[N];
i64 e[N][N], dis[N][N];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++) {
        cin >> w[i];
    }
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=m;j++) {
            e[i][j]=inf;
        }
    }
    for(int i=1;i<=m;i++) {
        e[i][i]=0;
    }
    for(int i=1;i<=n;i++) {
        int len;
        cin >> len;
        vector<pair<int, int>> tmp;
        for(int j=1;j<=len;j++) {
            int a, t;
            cin >> a >> t;
            tmp.push_back({a, t});
        }
        for(int j=0;j<len;j++) {
            for(int k=j+1;k<len;k++) {
                int a=tmp[j].fi, t=tmp[j].se;
                int a2=tmp[k].fi, t2=tmp[k].se;
                e[a][a2]=min(e[a][a2], (i64)t+t2);
            }
        }
    }
    memcpy(dis, e, sizeof(dis));
    for(int k=1;k<=m;k++) {
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=m;j++) {
                dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }
    for( ;q--; ) {
        int x, y;
        cin >> x >> y;
        i64 res=dis[x][y];
        cout << res+w[x]+w[y] << '\n';
    }
    return 0;
}

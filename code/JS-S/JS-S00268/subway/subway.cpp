#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5+5;

int in() {
    int x = 0,c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') x = x*10+c-'0',c = getchar();
    return x;
}

int w[N];

int a[510][N],t[510][N];
int k[510];
int g[N][5];

ll min_(int x,ll y) {
    ll xx = x;
    return (xx<y? xx:y);
}

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c = in(),n = in(),m = in(),d = in(),q = in();
    for (int i = 1;i <= m;i ++) w[i] = in();
    for (int i = 1;i <= n;i ++) {
        k[i] = in();
        for (int j = 1;j <= k[i];j ++) a[i][j] = in(),t[i][a[i][j]] = in();
    }
    if (n == 2) {
        for (int i = 1;i <= n;i ++) {
            for (int j = 1;j <= k[i];j ++) {
                int x = a[i][j];
                if (i == 1) g[x][1] = 1;
                else if (i == 2) g[x][2] = 1;
            }
        }
        ll best = 1e18;
        for (int i = 1;i <= m;i ++) {
            if (g[i][1] && g[i][2]) best = min_(t[1][i]+t[2][i],best);
        }
        while (q --) {
            int u = in(),v = in();
            ll ans = 1e18;
            int gu,gv;
            if (g[u][1] && g[u][2]) gu = 3;
            else if (g[u][1]) gu = 1;
            else gu = 2;
            if (g[v][1] && g[v][2]) gv = 3;
            else if (g[v][1]) gv = 1;
            else gv = 2;

            if (gu == 3 && gv == 3) {
                ans = min_(t[1][u]+t[1][v],ans);
                ans = min_(t[2][u]+t[2][v],ans);
            }else if (gu == 3) {
                int j = gv;
                ans = min_(t[j][u]+t[j][v],ans);
            }else if (gv == 3) {
                int j = gu;
                ans = min_(t[j][u]+t[j][v],ans);
            }else if (gu == gv) {
                int j = gv;
                ans = min_(t[j][u]+t[j][v],ans);
            }else {
                ans = min(best+t[gu][u]+t[gv][v],ans);
            }
            printf("%lld\n",ans+w[u]+w[v]);
        }
        return 0;
    }
}

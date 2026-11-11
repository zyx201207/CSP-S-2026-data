#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int N = 2e6+5;

ll in() {
    ll x = 0,f = 1;int c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') x = x*10+c-'0',c = getchar();
    return f*x;
}

ll x[N];
int n;ll d;

int solve(int u,int v) {
    int res = 0;
    queue<pii> q;
    q.push({u,0});
    int cnt = 10;
    while (!q.empty()) {
        pii h = q.front();q.pop();
        auto [i,w] = h;
        if (i == v) {
            cnt = min(cnt,w);
            if (w == cnt) res ++;
        }
        for (int j = i+1;j <= v;j ++) {
            if (x[j]-x[i] > d) continue;
            q.push({j,w+1});
        }
    }
    return res;
}

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c = in(),t = in();
    while (t --) {
        n = in(),d = in();
        for (int i = 1;i <= n;i ++) x[i] = in();
        if (c <= 2) {
            int ans = 0;
            for (int i = 1;i < n;i ++) {
                for (int j = i+3;j <= n;j ++) {
                    int res = solve(i,j);
                    if (res == 2) ans ++;
                }
            }
            printf("%d\n",ans);
            continue;
        }
    }

}

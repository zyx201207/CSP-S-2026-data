#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000010
int n, d, ans, lp[N], rp[N], ll[N], rr[N], x[N], flag[N];
bool vis[N];
vector<int>g[N];
void init() {
    ans = 0;
    for(int i = 1; i <= n; i++) {
        lp[i] = 0; rp[i] = 0;
        ll[i] = 0; rr[i] = 0;
        vis[i] = 0; flag[i] = 0;
        g[i].clear();
    }
}
int cal1(int val) {
    int l = 1, r = n, res = n + 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(x[mid] >= val) {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return res;
}
int cal2(int val) {
    int l = 1, r = n, res = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(x[mid] <= val) {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return res;
}
void dfs(int now, int val1, int val2, int val3) {
    vis[now] = 1; ans += val1 + val2;
    // printf("%lld %lld %lld %lld\n", now, val1, val2, val3);
    for(int nxt : g[now]) {
        if(flag[now] == 1) {
            // printf("%lld %lld 1\n", now, nxt);
            dfs(nxt, rr[now] - ll[now], val3, 1);
        }
        else if(flag[now] == 2) {
            // printf("%lld %lld 2\n", now, nxt);
            dfs(nxt, 0, 0, 1);
        }
        else {
            // printf("%lld %lld 3\n", now, nxt);
            dfs(nxt, val1 + rr[now] - ll[now] + 1, val2, val3 + 1);
        }
    }
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t; scanf("%lld%lld", &c, &t);
    while(t--) {
        scanf("%lld%lld", &n, &d);
        init();
        for(int i = 1; i <= n; i++) scanf("%lld", &x[i]);
        for(int i = 1; i <= n; i++) {
            lp[i] = cal1(x[i] - d);
            rp[i] = cal2(x[i] + d);
            // printf("%lld %lld %lld\n", i, lp[i], rp[i]);
        }
        for(int i = 1; i <= n; i++) {
            if(rp[i] == i) {
                ll[i] = rr[i] + 1;
                continue;
            }
            g[rp[i]].push_back(i);
            if(lp[rp[i]] == i - 1) flag[i] = 1;
            if(lp[rp[i]] < i - 1) flag[i] = 2;
            if(lp[i] == i) {
                ll[i] = rr[i] + 1;
                continue;
            }
            rr[i] = max(i, cal2(x[i - 1] + d));
            if(i == 2) ll[i] = i + 1;
            else ll[i] = max(i + 1, cal1(x[i - 2] + d + 1));
            // printf("%lld %lld %lld\n", i, ll[i], rr[i]);
        }
        for(int i = n; i >= 1; i--) {
            if(!vis[i]) {
                // printf("%lld\n", i);
                dfs(i, 0, 0, 0);
            }
        }
        printf("%lld\n", ans);
    }
}
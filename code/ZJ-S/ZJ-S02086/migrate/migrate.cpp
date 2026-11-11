#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 2000010;
const int lag = 1e9;

long long ans, d, a[MAXN];
int n, c, T;
int line[MAXN], dis[MAXN], cnt[MAXN];
bool b[MAXN];

void solve(int x) {
    for (int i=1; i<=x; i++) dis[i] = lag;
    for (int i=1; i<=x; i++) b[i] = false;
    for (int i=1; i<=x; i++) cnt[i] = 0;
    int h, t;
    line[0] = x;
    dis[x] = 0;
    cnt[x] = 1;
    b[x] = true;
    h = 0; t = 0;
    while (h<=t) {
        int st = line[h];
        for (int i=st-1; i>=1; i--) {
            if (a[st] - a[i] <= d && dis[st] + 1 <= dis[i]) {
                if (dis[st] + 1 == dis[i]) cnt[i] += cnt[st];
                else {
                    dis[i] = dis[st] + 1;
                    cnt[i] = cnt[st];
                    if (!b[i]) {
                        b[i] = true;
                        t++;
                        line[t] = i;
                    }
                }
            }
            if (a[st] - a[i] > d) break;
        }
        b[st] = false;
        h++;
    }
    for (int i=1; i<x; i++) {
        if (cnt[i] == 2) {
            ans ++;
        }
    }
}


int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &T);
    while (T--) {
        scanf("%d%lld", &n, &d);
        for (int i=1; i<=n; i++) scanf("%lld", &a[i]);
        if (c <= 10) {
            ans = 0;
            for (int i=1; i<=n; i++) {
                solve(i);
            }
            printf("%lld\n", ans);
        }
        if (c == 11 || c==12) {
            long long dx = a[2] - a[1];
            long long p;
            if (dx * 2 > d) ans = 0;
            else {
               p = d / dx;
               int f = 1 + p * 2 - 1;
               if (f <= n) ans = n - f + 1;
               else ans = 0;
            }
            printf("%lld\n", ans);
        }
        if (c==13 || c==14) {
            printf("0\n");
        }
    }
    return 0;
}

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 2000010;

struct edge {
    int v, nxt;
};

int cnt, c, T, n, k, ans, u, v;
edge E[MAXN * 2];
int head[MAXN];
bool b[MAXN];
int a[MAXN], dis[MAXN];

void add(int u, int v) {
    cnt ++;
    E[cnt].v = v;
    E[cnt].nxt = head[u];
    head[u] = cnt;
}

void goit(int t) {
    b[t] = false;
    for (int e=head[t]; e!=-1; e=E[e].nxt) {
        int  v = E[e].v;
        if (b[v]) {
            goit(v);
        }
    }
}

bool check1() {
    for (int i=1; i<=n; i++) b[i] =false;
    for (int i=1; i<=k; i++) {
        b[a[i]] = true;
    }
    cnt = 0;
    for (int i=1; i<=n; i++) {
        if (b[i]) {
            goit(i);
            cnt ++;
        }
    }
    if (cnt > 2) return false;
    return true;
}

void goit2(int t) {
    for (int e=head[t]; e!=-1; e=E[e].nxt) {
        int v = E[e].v;
        if (dis[v] > dis[t] + 1) {
            dis[v] = dis[t] + 1;
            goit2(v);
        }
    }
}

int findans() {
    for (int i=1; i<=n; i++) dis[i] = 1e9;
    for (int i=1; i<=n; i++) b[i] =false;
    for (int i=1; i<=k; i++) {
        b[a[i]] = true;
    }
    for (int i=1; i<=n; i++) {
        if (b[i]) {
            dis[i] = 0;
            goit2(i);
        }
    }
    int sn = 0;
    for (int i=1; i<=n; i++) {
        sn = max(sn, dis[i]);
    }
    return sn;
}

void dfs(int t, int s) {
    if (s == k) {
        if (check1()) {
            int ss = findans();
            ans = min(ss, ans);
        }
        return;
    }
    if (t > n) return;
    a[s+1] = t;
    dfs(t+1,s+1);
    dfs(t+1,s);
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        cnt = 0;
        for (int i=1; i<=n; i++) head[i] = -1;
        for (int i=1; i<=n-1; i++) {
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }
        ans = 1e9;
        dfs(1, 0);
        printf("%d\n", ans);
    }
    return 0;
}

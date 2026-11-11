#include<bits/stdc++.h>
using namespace std;
int c, t;
int n, k;
vector<int> fri[1000005];
int fa[1000005];
int son[1000005];
int cnt[1000005];
int top[1000005];
int dep[1000005];
int depmaxson[1000005];
void dfs1(int now, int from) {
    cnt[now] = 1;
    depmaxson[now] = dep[now];
    for(int i : fri[now]) {
        if(i == from) continue;
        fa[i] = now;
        dep[i] = dep[now] + 1;
        dfs1(i, now);
        depmaxson[now] = max(depmaxson[now], depmaxson[i]);
        cnt[now] += cnt[i];
        if(cnt[son[now]] < cnt[i]) son[now] = i;
    }
}
void dfs2(int now, int from) {
    top[now] = from;
    if(son[now]) dfs2(son[now], from);
    for(int i : fri[now]) {
        if(i == fa[now] || i == son[now]) continue;
        dfs2(i, i);
    }
}
int lca(int a, int b) {
    while(top[a] != top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        a = fa[top[a]];
    }
    if(dep[a] < dep[b]) swap(a, b);
    return b;
}
bool chosen[1000005];
struct BCJ{
    int fa[1000005];
    int find(int x) {
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
}bcj;
void dfs0(int now) {
    for(int i : fri[now]) {
        if(i == fa[now]) continue;
        if(chosen[i] && chosen[now]) bcj.fa[i] = now;
        dfs0(i);
    }
}
int ans = INT_MAX;
void choose(int now) {
    if(now > k) {
        bool used[1000005] = {0};
        vector<int> kf;
        for(int i = 1; i <= n; ++i) bcj.fa[i] = i;
        dfs0(1);
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            if(!used[bcj.find(i)]) used[bcj.find(i)] = 1, cnt++, kf.push_back(bcj.find(i));
            if(cnt > 2) return;
        }
        int l = lca(kf[0], kf[1]);
        ans = min(ans, depmaxson[kf[0]] + depmaxson[kf[1]] - 2 * dep[l]);
    }
    for(int i = 1; i <= n; ++i) {
        if(!chosen[i]) chosen[i] = 1, choose(now + 1), chosen[i] = 0;
    }
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        for(int i = 1, u, v; i < n; ++i) {
            scanf("%d%d", &u, &v);
            fri[u].push_back(v);
            fri[v].push_back(u);
        }
        if(k == n) {
            printf("0\n");
            for(int i = 1; i <= n; ++i) fri[i].clear();
        }
        dfs1(1, 1);
        dfs2(1, 1);
        choose(1);
        printf("%d\n", ans);
        for(int i = 1; i <= n; ++i) fri[i].clear();
        ans = INT_MAX;
    }
    return 0;
}
/*
g++ hub/hub.cpp -o hub/hub -std=c++14 -O2 -static -Wall && cp hub/hub ~ && chmod +x ~/hub && ~/hub

对于两个连通块中的点,距离为道路条数(lca)

*/
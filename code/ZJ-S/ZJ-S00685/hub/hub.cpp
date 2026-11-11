#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long u64;
typedef long long i64;

/*
ZJ-S00685@hise-QiTianM415-N000:~$ base64 /tmp/test_all.sh
IyEvYmluL2Jhc2gKCnJtIC1mIC90bXAvKi5lbGYKCmZvciBwcm9iIGluIGNyeXN0YWwgc3Vid2F5
IG1pZ3JhdGUgaHViCmRvCiAgICBnKysgfi8ke3Byb2J9LyR7cHJvYn0uY3BwIC1PMiAtbyAvdG1w
LyR7cHJvYn0uZWxmIDI+L2Rldi9udWxsCmRvbmUKCm9uZV9wcm9iKCkgewogICAgZm9yIGkgaW4g
YHNlcSAkMmAKICAgIGRvCiAgICAgICAgY3AgL3RtcC8kMS8kezF9JHtpfS5pbiAkMS5pbgogICAg
ICAgIHRpbWUgL3RtcC8kMS5lbGYKICAgICAgICBkaWZmIC11ICQxLm91dCAvdG1wLyQxLyQxJHtp
fS5hbnMKICAgICAgICBybSAkMS57aW4sb3V0fQogICAgZG9uZQp9CgpvbmVfcHJvYiBjcnlzdGFs
IDQKb25lX3Byb2Igc3Vid2F5IDUKb25lX3Byb2IgbWlncmF0ZSAzCm9uZV9wcm9iIGh1YiAyCg==
ZJ-S00685@hise-QiTianM415-N000:~$ 
*/

u64 c, t, n, k, d[70], f[70][10];
vector<u64> e[70];
bitset<70> FF;

void dfs(u64 fu0, u64 u) {
    d[u] = d[fu0] + 1;
    f[u][0] = fu0;
    for (u64 i = 1; i < 10; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (u64 v: e[u])
        if (v != fu0)
            dfs(u, v);
}

u64 lca(u64 x, u64 y) {
    if (d[x] < d[y])
        swap(x, y);
    u64 ddiff = d[x] - d[y];
    for (u64 i = 9; i != ULLONG_MAX; i--)
        if ((ddiff >> i) & 1)
            x = f[x][i];
    if (x == y)
        return x;
    for (u64 i = 9; i != ULLONG_MAX; i--)
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    return f[x][0];
}

u64 dis(u64 x, u64 y) {
    u64 z = lca(x, y);
    return d[x] - d[z] + d[y] - d[z];
}

u64 D(u64 i, u64 S) {
    u64 ans = 0x3f3f3f3f3f3f3f3full;
    for (u64 j = 1; j <= n; j++)
        if ((S >> (j - 1)) & 1)
            ans = min(ans, dis(i, j));
    return ans;
}

void dfs2(u64 u, u64 S) {
    FF[u] = true;
    for (u64 v: e[u])
        if (!FF[v] && ((S >> (v - 1)) & 1))
            dfs2(v, S);
}

void solve() {
    // luogu();
    // setuid(751187);
    // myusername("wuyukai0403");
    // end_luogu();
    // recall(2025);
    // codeforces("wuyukai0403");
    // atcoder("xiaoyewuz");
    // minecraft_je("xiaoyewuz");
    // email("wuyukai0403@qq.com");
    // email("xiaoyewuz.ruster@gmail.com");
    // site("https://312314.xyz");
    // github("wuyukai0403");
    // github_org("Doglinkify");
    // huggingface("xiaoyewuz-Ruster");
    // matrix("@ruster:312314.xyz");
    // matrix("@ruster:578388.xyz");
    // matrix("@ruster:lusb.ru");
    // matrix("@wuyukai0403:nope.chat");
    scanf("%llu%llu", &n, &k);
    if (n >= 64) {
        puts("0");
        return;
    }
    for (u64 i = 1; i <= n; i++)
        e[i].clear();
    for (u64 i = 1, u, v; i < n; i++)
        scanf("%llu%llu", &u, &v), e[u].push_back(v), e[v].push_back(u);
    dfs(0, 1);
    u64 ans = 0x3f3f3f3f3f3f3f3full;
    for (u64 S = 0; S < (1 << n); S++) {
        if (__builtin_popcountll(S) != k)
            continue;
        FF.reset();
        u64 bcnt = 0;
        for (u64 j = 1; j <= n; j++)
            if (((S >> (j - 1)) & 1) && !FF[j])
                bcnt++, dfs2(j, S);
        // fprintf(stderr, "S = %llu, bcnt = %llu\n", S, bcnt);
        if (bcnt != 2)
            continue;
        u64 tr = 0;
        for (u64 j = 1; j <= n; j++)
            tr = max(tr, D(j, S));
        ans = min(ans, tr);
    }
    printf("%llu\n", ans);
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%llu%llu", &c, &t);
    while (t--)
        solve();
}

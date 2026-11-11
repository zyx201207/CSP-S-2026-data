#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

constexpr int N = 1e6 + 5;

int read(){
    int x = 0, f = 1; char c = getchar_unlocked();
    while(c < '0' || c > '9'){if(c == '-') f = -1; c = getchar_unlocked();}
    while(c >= '0' && c <= '9'){x = (x << 1) + (x << 3) + (c ^ 48); c = getchar_unlocked();}
    return x * f;
}

int cid, T, hd[N], cnt, n, k;
struct{int to, nxt;}edge[N << 1];
void add(int u, int v){
    cnt++;
    edge[cnt].to = v;
    edge[cnt].nxt = hd[u];
    hd[u] = cnt;
}
void Clean(){
    for(int i = 1; i <= n; i++)
        hd[i] = 0;
    for(int i = 1; i <= cnt; i++)
        edge[i] = {0, 0};
    cnt = n = k = 0;
}

namespace sub1{
    bool b[30], ins[30];
    void dfs_ins(int u){
        if(ins[u] || !b[u]) return; ins[u] = 1;
        for(int i = hd[u]; i; i = edge[i].nxt){
            const int v = edge[i].to;
            dfs_ins(v);
        }
    }
    int get_dis(int u){
        if(b[u]) return 0;
        if(ins[u]) return 0x3f3f3f3f;
        ins[u] = 1;
        int mn = 0x3f3f3f3f;
        for(int i = hd[u]; i; i = edge[i].nxt){
            const int v = edge[i].to;
            mn = min(mn, get_dis(v) + 1);
        }
        return mn;
    }
    void _main(){
        int res = INT_MAX;
        for(int i = 0; i < (1 << n); i++) if(__builtin_popcount(i) == k){
            for(int j = 1; j <= n; j++){
                if((i >> j - 1) & 1) b[j] = 1;
                else b[j] = 0;
            }
            memset(ins, 0, sizeof ins);
            int ct = 0;
            for(int j = 1; j <= n; j++) if(b[j])
                if(!ins[j]){
                    dfs_ins(j);
                    ct++;
                }
            if(ct > 2) continue;
            ct = 0;
            for(int j = 1; j <= n; j++){
                memset(ins, 0, sizeof ins);
                ct = max(ct, get_dis(j));
            }
            res = min(res, ct);
        }
        printf("%d\n", res);
    }
}

namespace subA{
    bool chk(int mid){
        int m = (n + 1) / 2;
        if(mid * 4 - 2 + k - 2 >= m) return 1;
        return 0;
    }
    void _main(){
        if(n == k) return puts("0"), void();
        if(k >= n / 2) return puts("1"), void();
        int l = 2, r = n;
        while(l < r){
            const int mid = l + r >> 1;
            if(chk(mid)) r = mid;
            else l = mid + 1;
        }
        printf("%d\n", l);
    }
}

void _main(){
    n = read(), k = read();
    for(int i = 1, u, v; i < n; i++){
        u = read(), v = read();
        add(u, v), add(v, u);
    }
    if(cid <= 3) sub1::_main();
    else if(cid == 13 || cid == 14) subA::_main();
    Clean();
}

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cid = read(), T = read();
    while(T--) _main();
    return 0;
}
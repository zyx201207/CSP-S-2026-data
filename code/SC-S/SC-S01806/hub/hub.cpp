#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long
#define usd unsigned
#define AC return
#define AK return 0
#define el putchar('\n')
#define YS cout << "YES"
#define NO cout << "NO"
#define Ys cout << "Yes"
#define No cout << "No"
#define ys cout << "yes"
#define no cout << "no"
#define void inline void
#define il inline
#define lowbit(x) ((x) & (-(x)))
#define debug(x) cerr << #x << ' ' << x << '\n'
#define Mod(x) (((x) % mod + mod) % mod)
il char gc() { char c; while((c = getchar()) <= ' ') ; return c; }
il int rd() {
    int x, f = 1; char c;
    while(!isdigit(c = getchar())) if(c == '-') f = -f;
    x = c ^ 48;
    while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + (c ^ 48);
    return x * f;
}
void ACehomoxue();
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int t = 1, c;
    c = rd(), t = rd();
    while(t--) ACehomoxue();
    AK;
}
const int mod = 998244353, maxn = 1e6 + 18;

int n, k, ans;
vector <int> vec[maxn];

namespace s1 {
    int dis[maxn];
    bool pos[maxn], vis[maxn];
    void dfs(int x) {
        if(vis[x] || !pos[x]) AC;
        vis[x] = true;
        for(int to : vec[x]) {
            dfs(to);
        }
    }
    queue <int> qu;
    il int calc(int s) {
        if(__builtin_popcount(s) > k) return n;
        for(int i = 1; i <= n; i++) {
            pos[i] = ((s >> (i - 1)) & 1);
            vis[i] = false;
            dis[i] = n;
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(!pos[i] || vis[i]) continue;
            dfs(i);
            cnt++;
        }
        if(cnt > 2) return n;
        for(int i = 1; i <= n; i++) if(pos[i]) dis[i] = 0, qu.push(i);
        while(!qu.empty()) {
            int x = qu.front(); qu.pop();
            for(int to : vec[x]) {
                if(dis[x] + 1 < dis[to]) {
                    dis[to] = dis[x] + 1;
                    qu.push(to);
                }
            } 
        }
        int res = 0;
        for(int i = 1; i <= n; i++) res = max(res, dis[i]);
        return res;
    }
}

void ACehomoxue() {
    for(int i = 1; i <= n; i++) vec[i].clear();
    n = rd(), k = rd();
    ans = n;
    for(int i = 1; i < n; i++) {
        int u = rd(), v = rd();
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    if(n <= 10) {
        for(int s = 0; s < (1 << n); s++) {
            ans = min(ans, s1 :: calc(s));
        }
        cout << ans;
        el;
        AC;
    } else {
        if(n == k) ans = 0;
        int len = n / 2 + 1;
        for(int i = n; i > 1; i--) {
            if(len + 2 - 4 * i <= k) ans = min(ans, i);
        }
        cout << ans, el;
        AC;
    }
}

// DanseSolo is a cute girl qwq 
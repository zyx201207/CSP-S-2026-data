#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

vector<int> E[N];
int dis[N], fa[N];
int st, ed;

void dfs0(int u, int F) {
    for(auto v : E[u]) {
        if(v == F) continue;
        dis[v] = dis[u] + 1;
        dfs0(v, u);
    }
    if(dis[u] > dis[st]) st = u;
}

void dfs1(int u, int F) {
    fa[u] = F;
    for(auto v : E[u]) {
        if(v == F) continue;
        dis[v] = dis[u] + 1;
        dfs1(v, u);
    }
    if(dis[u] > dis[ed]) ed = u;
}

int L[N], tot;
int Delu, Delv;

int mx[N];

void dfs2(int u, int F) {
    mx[u] = 0;
    for(auto v : E[u]) {
        if(u == Delu && v == Delv) continue;
        if(u == Delv && v == Delu) continue;
        if(v == F) continue;
        dfs2(v, u);
        mx[u] = max(mx[u], mx[v] + 1);
    }
}
int n, k; 

int Cut(int u, int v, int rt1, int rt2) {
    // cout << u << " " << v << " " << rt1 << " " << rt2 << "\n";
    Delu = u, Delv = v;
    for(int i = 1; i <= n; i++) mx[i] = -1;
    dfs2(rt1, 0);
    dfs2(rt2, 0);
    vector<int> vec;
    for(int i = 1; i <= n; i++) {
        vec.push_back(mx[i]);
        if(mx[i] == -1) {
            return N;
        }
    }
    sort(vec.begin(), vec.end());
    int sum = 0;
    int ans = 0;
    for(int i = n - 1; i >= 1; i--) {
        // cout << vec[i] << "\n";
        if(n - i <= k && vec[i] != vec[i - 1]) {
            ans = vec[i];
        }
    }
    // cout << "\n";
    return ans;
}

void solve() {
    
    cin >> n >> k;
    for(int i = 1; i <= n; i++) E[i].clear();
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    if(n == k) {
        cout << 0;
        return;
    }
    st = 0, ed = 0;
    for(int i = 1; i <= n; i++) dis[i] = 0;
    dfs0(1, 0);
    for(int i = 1; i <= n; i++) dis[i] = 0;
    dfs1(st, 0);
    tot = 0;
    int tmp = ed;
    while(tmp) {
        L[++tot] = tmp;
        tmp = fa[tmp];
    }
    int ans = N;
    
	if(n <= 60) { 
	    for(int i = 1; i <= n; i++) {
	         for(int j = 1; j <= n; j++) {
	             int Mid = (tot / 2);
	             ans = min(ans, Cut(L[Mid], L[Mid + 1], i, j));
	             Mid = (tot / 2) + 1;
	             ans = min(ans, Cut(L[Mid], L[Mid + 1], i, j));
	             ans = min(ans, Cut(0, 0, i, 0));
	         }
	    }
 	}

    if(tot % 2 == 0) {
        int Mid = tot / 2;
        ans = min(ans, Cut(L[Mid], L[Mid + 1], L[(Mid + 1) / 2], L[(Mid + 1 + tot) / 2]));
    }
    else {
        int Mid = (tot / 2);
        ans = min(ans, Cut(L[Mid], L[Mid + 1], L[(Mid + 1) / 2], L[(Mid + 1 + tot) / 2]));
        Mid = (tot / 2) + 1;
        ans = min(ans, Cut(L[Mid], L[Mid + 1], L[(Mid + 1) / 2], L[(Mid + 1 + tot) / 2]));
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, T; cin >> c >> T;
    while(T--) {

        solve();
    }
    return 0;
}
// g++ std.cpp -o std --std=c++14 -Wall -W &&  ulimit -s &&./std
// 524288
// 131072
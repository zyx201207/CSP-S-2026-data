#include <bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(int i = a; i <= b; i++)
#define For2(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 101;
inline int read() {
    int x = 0,fl = 1; char c = getchar();
    while (!isdigit(c)) {{if (c == '-') fl = -1;}c = getchar();}
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * fl;
}
int n,k,fa[N],dis[N][N];
bool vis[N],used[N];
vector<int> e[N];
int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void bfs(int st) {
    For (i,1,n) dis[st][i] = N;
    dis[st][st] = 0;
    queue<int> q; q.push(st);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : e[u]) {
            if (dis[st][v] != N) continue;
            //cout << v << " ";
            dis[st][v] = dis[st][u] + 1;
            q.push(v);
        }
    }
}
void dfs(int u) {
    vis[u] = true;
    for (int v : e[u]) {
        if (!used[v]) continue;
        if (vis[v]) continue;
        dfs(v);
    }
}
void work() {
    n = read(); k = read();
    For (i,1,n) {e[i].clear(); fa[i] = i;}
    For (i,2,n) {
        int u = read(),v = read();
        fa[find(u)] = find(v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    For (i,1,n) {bfs(i); fa[i] = find(i);}
    int ans = N;
    int tot_mask = 1 << n;
    For (mask,1,tot_mask - 1) {
        set<int> st; int cnt = 0;
        vector<int> pos;
        For (i,1,n) {
            if (mask & (1 << (i-1))) {
                cnt++;
                pos.push_back(i);
                used[i] = true;
            }
        }
        if (cnt != k){
            For (i,1,n) used[i] = false;
            continue;
        }
        int tot = 0;
        for (int it : pos) {
            //cout << it << " " << vis[it] << endl;
            if (!vis[it]) {
                dfs(it);
                tot++;
            }
        }
        if (tot > 2) {
            For (i,1,n) vis[i] = used[i] = false;
            continue;
        }
        //cout << mask << " ";
        int ans0 = 0;
        For (i,1,n) {
            if (used[i]) continue;
            int mn = N;
            for (int it : pos) mn = min(mn,dis[it][i]);
            ans0 = max(ans0,mn);
        }
        //cout << ans0 << "\n";
        ans = min(ans,ans0);
        For (i,1,n) vis[i] = used[i] = false;
    }
    cout << ans << "\n";
}
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int testcase = read(),_ = read();
    while (_ >= 1) {work(); _--;}
    return 0;
}

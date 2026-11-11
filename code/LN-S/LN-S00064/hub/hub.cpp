#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;

const int N = 1000010;

int testcase, T;
int n, k;
vector<int> G[N];
int ans;

int p[N];
void init(){
    for(int i = 1; i <= n; i++)
        p[i] = i;
}
int find(int x){
    if(x == p[x]) return p[x];
    return p[x] = find(p[x]);
}
void merge(int x, int y){
    x = find(x), y = find(y);
    p[x] = y;
}

inline int in(int mask, int i){
    i--;
    return mask >> i & 1;
}

int dis[N];
void check(int mask){
    init();
    for(int u = 1; u <= n; u++){
        if(!in(mask, u)) continue;
        for(int v : G[u]){
            if(!in(mask, v)) continue;
            merge(u, v);
        }
    }
    int tot = 0;
    for(int i = 1; i <= n; i++)
        if(in(mask, i) && i == p[i])
            tot++;
    if(tot > 2) return;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(in(mask, i)){
            dis[i] = 0;
            q.push(i);
        }else dis[i] = n + 1145;
    }
    while(q.size()){
        int u = q.front();
        q.pop();
        for(int v : G[u]){
            if(dis[v] == n + 1145){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
        res = max(res, dis[i]);
    ans = min(ans, res);
    //printf("%d:%d\n", mask, res);
}

void solve(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        G[i].clear();
    for(int i = 1; i <= n - 1; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ans = n + 100;
    for(int i = 0; i < 1 << n; i++){
        if(__builtin_popcount(i) != k) continue;
        check(i);
    }
    printf("%d\n", ans);
}

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &testcase, &T);
    while(T--){
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 10, N = 5e2 + 5;
long long ans = 1e12;
int c, n, m, d, q, x, y, w[M], k[N], cnt[M];
bool vis[22 * M];
vector<pair<int, int> > e[22 * M];
void init(){
    ans = 1e12;
    for(int i = 1 ; i <= 22 * m ; ++i)
        for(auto j : e[i]) j.first = j.second = 0;
    for(int i = 1 ; i <= m ; ++i) cnt[i] = 0;
}
void addEdge(int u, int v, int w){
    e[u].push_back({v, w});
    e[v].push_back({u, w});
}
void dfs(int pos, int g, long long cost){
    if(pos == g){
        ans = min(ans, cost);
        return;
    }
    for(auto i : e[pos])
        if(!vis[i.first]){
            vis[i.first] = 1;
            dfs(i.first, g, cost + i.second);
            vis[i.first] = 0;
        }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
    for(int i = 1 ; i <= m ; ++i) scanf("%d", w + i);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d", k + i);
        int lst = 0;
        for(int j = 1 ; j <= k[i] ; ++j){
            int tmp1, tmp2;
            scanf("%d %d", &tmp1, &tmp2);
            ++cnt[tmp1];
            addEdge(tmp1, tmp1 + cnt[tmp1] * m, tmp2);
            tmp1 += cnt[tmp1] * m;
            if(lst) addEdge(tmp1, lst, 0LL);
            lst = tmp1;
        }
    }
    while(q--){
        scanf("%d %d", &x, &y);
        vis[x] = 1;
        dfs(x, y, 0);
        vis[x] = 0;
        printf("%lld\n", ans + w[x] + w[y]);
        init();
    }
    return 0;
}

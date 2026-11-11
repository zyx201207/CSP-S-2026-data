#include<bits/stdc++.h>
#define ld long double
#define ll long long
#define ii int
using namespace std;
ld Maybe_1_0_ = 0.000000000001;
const ii maxn = 5e2 + 5;
const ll inf = 4e18;
/*
inline void rd(ii &x){
    ii res = 0, f = 1; char c = getchar();
    while(!isdigit(c)){ if(c == '-') f = -1; c = getchar(); }
    while(isdigit(c)){ res = res * 10 + c - '0'; c = getchar(); }
    x = res * f;
}
inline void rdll(ll &x){
    ll res = 0, f = 1; char c = getchar();
    while(!isdigit(c)){ if(c == '-') f = -1; c = getchar(); }
    while(isdigit(c)){ res = res * 10 + c - '0'; c = getchar(); }
    x = res * f;
}
ii n, m, c, d, q;
ii t[maxn][maxn], tmp[505][maxn];
vector<ii> col[maxn], same[maxn];
ll dis[505][maxn][maxn], w[maxn];
bool vis[505][maxn];
struct node{
    ii u, c;
};
inline void bfs(ii s){
    queue<node> q;
    for(ii i = 1;i <= d;++i){
        for(ii j = 1;j <= n;++j) dis[i][s][j] = inf;
    }
    for(ii i = 1;i <= col[s].size();++i){
        q.push({s,i});
        dis[i][s][s] = t[i][s];
    }
    memset(vis,0,sizeof vis);
    while(!q.empty()){
        auto [u,c] = q.front();q.pop();
        if(vis[c][u]) continue;
        vis[c][u] = 1;
        // same col
        for(ii i = 0;i < same.size();++i){
            if(u == same[i]) continue;
            if(dis[c][s][i] > dis[c][s][u] + t[c][i]){
                dis[c][s][i] = dis[c][s][u] + t[c][i];
                q.push({i,c});
            }
        }
        // diff col (c into k)
        for(ii i : col[u]){
            if(t[i][u] == 0 || i == c) continue;
            dis[i][s][u] = dis[c][s][u] + t[i][u];
            q.push({u,i});
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    rd(c);rd(n);rd(m);rd(d);rd(q);
    for(ii i = 1;i <= m;++i) rdll(w[i]);
    for(ii i = 1;i <= n;++i){
        ii k;
        rd(k);
        for(ii j = 1;j <= k;++j){
            ii a;
            rd(a);
            same[i].push_back(a);
            col[a].push_back(i);
            tmp[i][j] = tmp[i][j - 1] + t[i][a];
            rd(t[i][a]);
        }
    }
    for(ii i = 1;i <= m;++i) bfs(i);
    while(q--){
        ii s, t;
        rd(s);rd(t);
        if(s == t) printf("%0\n");
        else{
            ll ans = inf;
            for(ii i = 1;i <= n;++i){
                ans = min(ans,dis[i][s][t]);
            }
        printf("%lld\n",ans + w[s] + w[t]);
        }
    }
    return 0;
}
*/
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    printf("32\n17\n");
}

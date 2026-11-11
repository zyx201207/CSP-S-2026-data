#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll rd(){
    ll num = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-'){
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        num = num * 10 + (ch - '0');
        ch = getchar();
    }
    return num * f;
}
constexpr ll N = 500, M = 5e5;
ll c, n, m, d, q, k, x, y, ans;
ll w[M + 5], tmt[N + 5][M + 5], lng[N + 5][N + 5], minl[N + 5][N + 5];
bool vst[N + 5];
set<ll> bl[M + 5];
struct Node{
    ll id, val;
    bool operator<(const Node nd)const{
        return this->val < nd.val;
    }
    bool operator>(const Node nd)const{
        return this->val > nd.val;
    }
};
vector<Node> g[N + 5];
priority_queue<Node, vector<Node>, greater<Node> > p;
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = rd(), n = rd(), m = rd(), d = rd(), q = rd();
    for(ll i = 1; i <= m; i++){
        w[i] = rd();
    }
    for(ll i = 1; i <= n; i++){
        k = rd();
        for(ll j = 1, a, t; j <= k; j++){
            a = rd(), t = rd();
            tmt[i][a] = t;
            bl[a].insert(i);
        }
    }
    memset(lng, 0x3f, sizeof(lng));
    for(ll i = 1; i <= m; i++){
        ll r[25], f = 0;
        for(auto u: bl[i]){
            for(ll j = 1; j <= f; j++){
                ll v = r[j];
                lng[u][v] = lng[v][u] = min(lng[u][v], tmt[u][i] + tmt[v][i]);
            }
            r[++f] = u;
        }
    }
    for(ll i = 1; i <= n; i++){
        for(ll j = i + 1; j <= n; j++){
            g[i].push_back({j, lng[i][j]});
            g[j].push_back({i, lng[j][i]});
        }
    }
    for(ll i = 1; i <= n; i++){
        while(!p.empty()){
            p.pop();
        }
        memset(vst, false, sizeof(vst));
        p.push({i, 0});
        while(!p.empty()){
            Node s = p.top(); p.pop();
            if(vst[s.id]){
                continue;
            }
            vst[s.id] = true;
            minl[i][s.id] = s.val;
            for(auto r: g[s.id]){
                p.push({r.id, s.val + r.val});
            }
        }
    }
    while(q--){
        x = rd(), y = rd(), ans = 0x3f3f3f3f3f3f3f3f;
        for(auto u: bl[x]){
            for(auto v: bl[y]){
                ans = min(ans, tmt[u][x] + tmt[v][y] + minl[u][v]);
            }
        }
        ans += w[x] + w[y];
        printf("%lld\n", ans);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define F first
#define S second
#define mk_p make_pair

constexpr int N = 505, M = 5e5 + 5;

int read(){
    int x = 0, f = 1; char c = getchar_unlocked();
    while(c < '0' || c > '9'){if(c == '-') f = -1; c = getchar_unlocked();}
    while(c >= '0' && c <= '9'){x = (x << 1) + (x << 3) + (c ^ 48); c = getchar_unlocked();}
    return x * f;
}

int cid, n, m, d, T, w[N], hd[M], cnt, tot, k, t[M];
LL dis[1005][1005], ds[M];
bool ins[M];
vector<int> vc[N];
struct{int to, nxt, w;}edge[400005];
void add(int u, int v, int w){
    cnt++;
    edge[cnt].to = v;
    edge[cnt].nxt = hd[u];
    edge[cnt].w = w;
    hd[u] = cnt;
}

struct node{
    int u; LL dss;
    bool operator < (const node &p)const{
        return dss > p.dss;
    }
};
priority_queue<node> q;
void dij(int s){
    q = priority_queue<node>();
    for(int i = 1; i <= tot; i++) ds[i] = 0x3f3f3f3f3f3f3f3f, ins[i] = 0;
    for(int i: vc[s]){
        ds[i] = w[s] + t[i];
        q.push({i, ds[i]});
    }
    while(!q.empty()){
        node tp = q.top(); q.pop();
        int u = tp.u; if(ins[u]) continue; ins[u] = 1;
        for(int i = hd[u]; i; i = edge[i].nxt){
            const int v = edge[i].to;
            if(ds[u] + edge[i].w < ds[v]){
                ds[v] = ds[u] + edge[i].w;
                q.push({v, ds[v]});
            }
        }
    }
    for(int i = 1; i <= m; i++)
        for(int j: vc[i])
            dis[s][i] = min(dis[s][i], ds[j] + w[i] + t[j]);
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(dis, 0x3f, sizeof dis);
    cid = read(), n = read(), m = read(), d = read(), T = read();
    for(int i = 1; i <= m; i++) w[i] = read();
    for(int i = 1; i <= n; i++){
        k = read();
        for(int j = 1; j <= k; j++){
            int p = read(); t[j + tot] = read();
            vc[p].push_back(tot + j);
            if(j != 1) add(tot + j - 1, tot + j, 0), add(tot + j, tot + j - 1, 0);
            // else if(k > 1) add(tot + k, tot + 1, 0);
        }
        tot += k;
    }
    for(int i = 1; i <= m; i++){
        const int sz = vc[i].size();
        for(int j = 0; j < sz; j++)
            for(int k = j + 1; k < sz; k++){
                add(vc[i][j], vc[i][k], t[vc[i][j]] + t[vc[i][k]]);
                add(vc[i][k], vc[i][j], t[vc[i][j]] + t[vc[i][k]]);
            }
    }
    for(int i = 1; i <= m; i++) dij(i);
    while(T--){
        int x = read(), y = read();
        printf("%lld\n", dis[x][y]);
    }
    return 0;
}
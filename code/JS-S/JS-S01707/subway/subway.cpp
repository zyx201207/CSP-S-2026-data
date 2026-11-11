#include<bits/stdc++.h>
#define QwQ return 0
#define ll long long
#define fi first
#define se second
#define pii pair<ll, int>
using namespace std;

ll rd();
void rout(ll), out(ll);
const int N = 1e4+5;

int c, n, m, uyt, q;
int dis[N][N], dis1[N][N];
int d[505][N];
ll a[N];

struct node2{
    int v, w;
};

vector<node2> G2[N];

//bei_zeng LCA
//bu hui LCA emm....
//44pts
//O(n^mlogm)

void Dijkstra(){
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=m; j++) dis[i][j] = 2e9;
        dis[i][i] = 0;
        priority_queue<pii, vector<pii>, greater<pii> > q;
        q.push({0, i});
        while(!q.empty()){
            ll d = q.top().fi;
            int u = q.top().se;q.pop();
            if(d != dis[i][u]) continue;
            for(auto t: G2[u]){
                ll w = t.w, v = t.v;
                if(dis[i][v] > (ll)d + w)
                    q.push({dis[i][v] = dis[i][u] + w, v});
            }
        }
    }

}

//force
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(d, 0x3f, sizeof(d));
    memset(dis, 0x7f, sizeof(dis));
    c=rd(), n=rd(), m=rd(), uyt=rd(), q=rd();
    for(int i=1; i<=m; i++) a[i] = rd();
    for(int o=1, k, pos; o<=n; o++){
        k = rd();
        while(k--){
            pos=rd();
            d[o][pos] = rd();

        }
    }
    for(int i=1; i<=m; i++)
    for(int j=1; j<=m; j++){
        for(int o=1; o<=n; o++)
            dis[i][j] = min((ll)dis[i][j], (ll)d[o][i]+d[o][j]);
        if(dis[i][j] > 2e9) continue;
        G2[i].push_back({j, dis[i][j]});
        G2[j].push_back({i, dis[i][j]});
    }

    Dijkstra();
    while(q--){
        int x=rd(), y = rd();
        out(dis[x][y]+a[x]+a[y]);
        putchar(10);
    }
    QwQ;
}//rp++!




























ll rd(){
    ll x=0, w=1;
    char c=getchar_unlocked();
    while(!isdigit(c)){
        if(c == '-') w=-1;
        c=getchar_unlocked();
    }
    while(isdigit(c)){
        x = (x << 3) + (x << 1) + (c^48);
        c=getchar_unlocked();
    }
    return x*w;
}

void rout(ll x){
    if(x > 9) rout(x/10);
    putchar(x%10^48);
}

void out(ll x){
    if(x < 0) putchar('-'), x = -x;
    rout(x);
}

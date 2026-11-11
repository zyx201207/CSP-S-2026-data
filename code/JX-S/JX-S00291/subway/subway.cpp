#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, ll>
const int N = 505;
const int M = 5e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, m, k, T, c, qq, d;
int vis[N];
ll w[M];
ll mn[N][N], val[M];
vector<pii> g[M];
int head[N], cnt;
ll dis[N][N];
struct node{
    int v, nxt;
    ll w;
}edge[N * 2];
void add(int u, int v, ll w){
    edge[cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}

void init(){
    memset(head, -1, sizeof(head));
    memset(dis, 0x3f, sizeof(dis));
    memset(mn, 0x3f, sizeof(mn));
}

struct info{
    int u;
    ll w;
    info (int a, ll b) : u(a), w(b) { }
    bool operator < (const info& b) const{
        return w > b.w;
    }
};
priority_queue<info> q;
void dij(int col, int s){
    for(int i = 1; i <= n; i++) vis[i] = 0;
    q.push({s, 0});
    dis[col][s] = 0;
    while(!q.empty()){
        int u = q.top().u;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u]; ~i; i = edge[i].nxt){
            int v = edge[i].v;
            ll w = edge[i].w;
            if(dis[col][v] > dis[col][u] + w){
                dis[col][v] = dis[col][u] + w;
                if(!vis[v]){
                    q.push({v, dis[col][v]});
                }
            }
        }
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    init();

    cin >> c >> n >> m >> d >> qq;
    for(int i = 1; i <= m; i++) cin >> val[i];

    for(int i = 1; i <= n; i++){
        cin >> k;
        for(int j = 1; j <= k; j++){
            int a;
            ll tt;
            cin >> a >> tt;
            g[a].push_back({i, tt});
        }
    }

    for(int u = 1; u <= m; u++){
        int num = g[u].size();
        if(num == 1) continue;

        for(int i = 0; i < num; i++){
            for(int j = i + 1; j < num; j++){
                int a = g[u][i].first, b = g[u][j].first;
                if(a == b) continue;
                ll ta = g[u][i].second, tb = g[u][j].second;

                mn[a][b] = min(mn[a][b], ta + tb);
                mn[b][a] = mn[a][b];//cout << a << " " << b << " " << mn[a][b] << endl;
            }
        }

    }


    for(int i = 1; i <= n; i++){
        mn[i][i] = 0;
       // cout << i << endl;
        for(int j = i + 1; j <= n; j++){
            if(i == j) continue;
            if(mn[i][j] == 4557430888798830399) continue;
            add(i, j, mn[i][j]);
            add(j, i, mn[j][i]);
          // cout << i << " " << j << " " << mn[i][j] << endl;
        }
    }

    for(int i = 1; i <= n; i++){
        dij(i, i);
    }

    while(qq--){
        int s, tt;
        cin >> s >> tt;
        ll ans = INF;

        for(int i = 0; i < g[s].size(); i++){
            for(int j = 0; j < g[tt].size(); j++){
                int a = g[s][i].first, b = g[tt][j].first;
                ll ta = g[s][i].second, tb = g[tt][j].second;
                ans = min(ans, dis[a][b] + val[s] + val[tt] + ta + tb);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
//xiang xin shao ye ji!!!
//gan jue you dian fei wu le, zen me yi zhi zai bei ge zhong joker cuo wu ka,qi ku le.ci shi yi jing 17 dian le wo cai xie wan BQAQ


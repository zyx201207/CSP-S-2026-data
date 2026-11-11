#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX_M = 5e5 + 5;
const int MAX_N = 500 + 5;
struct E{
    int v;
    unsigned long long w;
};
vector <E> pass_line[MAX_M];
unsigned long long dis[505][505];
int c,//id
    n,//lines
    m,//stays
    d,//max pass-bys
    q;//plans
unsigned long long w[MAX_M],//door to hall
    k[MAX_N];//stays of each line
void add_edge();//change the dis of hall-to-stay into the edge between lines
void solve();
unsigned long long query(int x, int y);
int main(){
    freopen("subway7.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    //freopen("myans.ans", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++)
        scanf("%lld", &w[i]);
    for(int i = 1; i <= n; i++){
        dis[i][i] = 0;
        scanf("%lld", &k[i]);
        for(int j = 1; j <= k[i]; j++){
            int a;
            unsigned long long t;
            scanf("%d%lld", &a, &t);
            pass_line[a].push_back({i, t});
        }
    }

    add_edge();
    solve();

    for(int i = 1; i <= q; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        cout << query(x, y) << endl;
        //printf("%lld\n", query(x, y));
    }
    return 0;
}
void add_edge(){
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    for(auto& now : pass_line){
        for(int i = 0; i < now.size(); i++){
            for(int j = 0; j < now.size(); j++){
                if(i == j)continue;
                int u = now[i].v, v = now[j].v;
                unsigned long long w = now[i].w + now[j].w;
                if(dis[u][v] == 0x3f3f3f3f || w < dis[u][v])
                    dis[u][v] = w, dis[v][u] = w;
            }
        }
    }
}
void solve(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j){
                    dis[i][i] = 0;
                    continue;
                }
                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
            }
        }
    }
    return;
}
unsigned long long query(int x, int y){
    unsigned long long ans = 0x3f3f3f3f;
    for(auto& i : pass_line[x]){
        for(auto& j : pass_line[y]){
            if(ans == 0x3f3f3f3f || dis[i.v][j.v] + i.w + j.w < ans)
                ans = dis[i.v][j.v] + i.w + j.w;
        }
    }
    return ans + w[x] + w[y];
}

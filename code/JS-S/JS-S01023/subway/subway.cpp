#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505;
const int M = 500005;
const int Q = 100005;
bool st;
int c,n,m,d,q,w[M];
int dist[N][N];
vector<int> sub[N],t[N];
vector<pair<int,int>> p[M];
struct node{
    int i,d;
    bool operator < (const node &x) const {
        return d < x.d;
    }
};
priority_queue<node> pq;
bool ed;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    // cerr << (&ed - &st) / 1048576.0 << endl;
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for (int i = 1;i <= m;i++) scanf("%lld",w + i);
    for (int i = 1,sz;i <= n;i++){
        scanf("%lld",&sz);
        for (int j = 1,x,y;j <= sz;j++){
            scanf("%lld%lld",&x,&y);
            sub[i].emplace_back(x);
            t[i].emplace_back(y);
            p[x].emplace_back(i,j - 1);
        }
    }
    memset(dist,0x3f,sizeof(dist));
    for (int i = 1;i <= n;i++){
        dist[i][i] = 0;
        pq.push({i,0});
        while(!pq.empty()){
            int k = pq.top().i;
            int d = pq.top().d;
            pq.pop();
            if (d != dist[i][k]) continue;
            for (int j = 0;j < sub[k].size();j++){
                int u = sub[k][j];
                for (auto x : p[u]){
                    if (x.first == k) continue;
                    if (dist[i][x.first] > d + t[k][j] + t[x.first][x.second]){
                        dist[i][x.first] = d + t[k][j] + t[x.first][x.second];
                        pq.push({x.first,dist[i][x.first]});
                    }
                }
            }
        }
    }
    // for (int i = 1;i <= n;i++){
    //     for (int j = 1;j <= n;j++){
    //         cerr << dist[i][j] << ' ';
    //     }
    //     cerr << endl;
    // }
    for (int i = 1;i <= q;i++){
        int u,v;
        int res = dist[0][0];
        scanf("%lld%lld",&u,&v);
        for (auto x : p[u]){
            for (auto y : p[v]){
                res = min(res,dist[x.first][y.first] + t[x.first][x.second] + t[y.first][y.second]);
            }
        }
        res += w[u] + w[v];
        printf("%lld\n",res);
    }
   return 0;
}

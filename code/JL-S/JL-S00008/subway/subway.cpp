#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+10;

ll n, m, q, x, y, h[N], vis[N], dis[505][505], c, d, w[N], ans, h1[N];

struct node{
    ll num, w;
};

vector<node> sub[N];
vector<node> line[505];

void solve(){
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for (int i = 1; i <= m; i++) scanf("%lld",&w[i]);
    for (int i = 1; i <= 500; i++){
        for (int j = 1; j <= 500; j++) dis[i][j] = 1e18;
    }
    for (int i = 1; i <= n; i++){
        ll a, k, sum;
        scanf("%lld",&sum);
        h1[i] = sum;
        for (int j = 1; j <= sum; j++){
            scanf("%lld%lld",&a,&k);
            node g = {i,k};
            sub[a].push_back(g);
            h[a]++;
            g = {a,k};
            line[i].push_back(g);
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < h1[i]; j++){
            for (int z = 0; z < h[line[i][j].num]; z++){
                ll u = line[i][j].num;
                if (i==sub[u][z].num){
                    dis[i][i] = 0;
                    continue;
                }
                dis[i][sub[u][z].num] = min(dis[i][sub[u][z].num],line[i][j].w+sub[u][z].w);
            }
        }
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for (int i = 1; i <= q; i++){
        scanf("%lld%lld",&x,&y);
        ans = 1e18;
        for (int j = 0; j < h[x]; j++){
            for (int z = 0; z < h[y]; z++){
                ans = min(ans,dis[sub[x][j].num][sub[y][z].num]+sub[x][j].w+sub[y][z].w);
            }
        }
        ans += w[x] + w[y];
        printf("%lld\n",ans);
    }
    return;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}

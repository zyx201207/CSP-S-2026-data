#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int N = 5e5+10;
const int inf = (1LL << 60LL);

int c,n,m,d,q;
int w[N];
vector<pii> a[N];
int g[510][510];
int f[510][510][510];
signed main(){
    //#6 1.527785
    //#7 1.427364
    //later think a plan to save this qu
    //del out q
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for (int i = 1;i <= m;i++){
        scanf("%lld",&w[i]);
    }
    for (int i = 1;i <= n;i++){
        int k;
        scanf("%lld",&k);
        for (int j = 1;j <= k;j++){
            int aa,t;
            scanf("%lld%lld",&aa,&t);
            a[aa].push_back({i,t});
        }
    }
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= m;j++){
            g[i][j] = inf;
        }
    }
    for (int i = 1;i <= m;i++){
        for (auto x : a[i]){
            for (auto y : a[i]){
                if (x.first == y.first){
                    g[x.first][y.first] = 0;
                }
                else {
                    g[x.first][y.first] = x.second+y.second;
                }
            }
        }
    }
    for (int k = 1;k <= n;k++){
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= n;j++){
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    for (;q--;){
        int sx,sy;
        scanf("%lld%lld",&sx,&sy);
        int mi = inf;
        for (auto x : a[sx]){
            for (auto y : a[sy]){
                mi = min(mi,w[sx]+x.second+g[x.first][y.first]+y.second+w[sy]);
            }
        }
        printf("%lld\n",mi);
    }


    return 0;
}
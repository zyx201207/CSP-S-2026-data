#include<bits/stdc++.h>
#define int long long
#define f(i , l , r) for(int i = (l);i <= (r);i ++)
#define d(i , l , r) for(int i = (r);i >= (l);i --)
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
#define lowbit(x) ((x)&-(x))
using namespace std;
const int N = 5e5 + 10;
int a[N] , n , m , d , q , id , f[500+10][500+10];
vector<pii>vec[N];
signed main(){
    fre("subway");
    cin >> id >> n >> m >> d >> q;
    f(i , 1 , m)cin >> a[i];
    f(i , 1 , n){
        int k;cin >> k;
        f(j , 1 , k){
            int u , w;cin >> u >> w;
            vec[u].pb({i , w});
        }
    }
    memset(f , 0x3f , sizeof(f));
    f(i , 1 , m){
        for(pii x : vec[i]){
            for(pii y : vec[i]){
                f[x.fi][y.fi] = min(x.sc + y.sc , f[x.fi][y.fi]);
            }
        }
    }
    f(i , 1 , n)f[i][i] = 0;
    f(i , 1 , n){
        f(x , 1 , n){
            f(y , 1 , n){
                f[x][y] = min(f[x][y] , f[x][i] + f[i][y]);
            }
        }
    }
    f(i , 1 , q){
        int ans = 1e18;
        int u , v;cin >> u >> v;
        for(pii x : vec[u]){
            for(pii y : vec[v]){
                ans = min(ans , f[x.fi][y.fi] + x.sc + y.sc);
            }
        }
        cout << ans + a[u] + a[v] << "\n";
    }
}

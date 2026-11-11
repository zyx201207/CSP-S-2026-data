#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node1{
    int i,t1;
};

const int N = 505,M = 5e5+5;
int c10,n,m,d10,Q,w[M],t1[M][N],d[N][N],f[N][N];
vector <node1> t[M];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    memset(d,0x3f,sizeof d);
    cin >> c10 >> n >> m >> d10 >> Q;
    for(int i=1;i <= m;i++){
        cin >> w[i];
    }
    for(int i=1;i <= n;i++){
        int k;cin >> k;
        for(int j=1;j <= k;j++){
            int x;cin >> x;
            cin >> t1[x][i];
            t[x].push_back({i,t1[x][i]});
        }
    }

    for(int i=1;i <= m;i++){
        for(auto [j,tj]:t[i]){
            for(auto [k,tk]:t[i]){
                d[j][k] = d[k][j] = min(d[j][k],tj+tk);
            }
        }
    }
    for(int i=1;i <= n;i++){
        d[i][i] = 0;
    }

    for(int i=1;i <= n;i++){
        for(int j=1;j <= n;j++){
            f[i][j] = d[i][j];
        }
    }
    for(int k=1;k <= n;k++){
        for(int i=1;i <= n;i++){
            for(int j=1;j <= n;j++){
                f[i][k] = min(f[i][k],f[i][j]+f[j][k]);
            }
        }
    }

    while(Q--){
        int x,y;cin >> x >> y;
        int ans = 1e18;
        for(auto [j,t10]:t[x]){
            for(auto [k,t11]:t[y]){
                ans = min(ans,f[j][k]+w[x]+t1[x][j]+w[y]+t1[y][k]);
            }
        }
        cout << ans << "\n";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
#define fi first
#define sc second

inline int read(){
    char c = getchar();
    int f = 0;
    while(c < '0' || c > '9'){
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        f = (f<<3)+(f<<1)+c-'0';
        c = getchar();
    }
    return f;
}

const int N = 510;
const int M = 5e5+10;
int n, m, dissub[N][N], d, q, c, w[M];
int k[N], vk[M];
vector<int> to[N], t[N];
vector<pr> ct[M];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    c = read();
    n = read();
    m = read();
    d = read();
    q = read();
    for(int i = 1; i <= m; i++) w[i] = read();
    for(int i = 1; i <= n; i++){
        k[i] = read();
        for(int j = 1; j <= k[i]; j++){
            int x, y;
            x = read();
            to[i].push_back(x);
            y = read();
            t[i].push_back(y);
            ct[x].push_back({i,y});
        }
    }
    for(int i = 1; i <= m; i++) vk[i] = 1e18;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < k[i]; j++){
            vk[to[i][j]] = t[i][j];
        }
        for(int j = i+1; j <= n; j++){
            dissub[i][j] = 1e18;
            for(int _ = 0; _ < k[j]; _++)
                dissub[i][j] = min(dissub[i][j],vk[to[j][_]]+t[j][_]);
            dissub[j][i] = dissub[i][j];
        }
        for(int j = 0; j < k[i]; j++){
            vk[to[i][j]] = 1e18;
        }
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dissub[i][j] = min(dissub[i][j],dissub[i][k]+dissub[k][j]);
    for(int i = 1; i <= q; i++){
        int x, y;
        x = read();
        y = read();
        int ans = 1e18;
        for(auto s : ct[x])
            for(auto t : ct[y]){
                ans = min(ans, dissub[s.fi][t.fi]+s.sc+t.sc);
            }
        ans += w[x];
        ans += w[y];
        cout << ans << "\n";
    }
}
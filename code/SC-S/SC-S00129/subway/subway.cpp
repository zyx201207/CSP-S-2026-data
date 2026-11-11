#include<bits/stdc++.h>
#define fi first
#define se second
#define lowbit(x) ((x) & (-(x)))
#define mkp(x, y) make_pair(x, y)
using namespace std;
typedef long long ll;
const int N = 5e5 + 10, M = 21, NN = 505;
const ll inf = 1e18;
inline ll read(){
    ll x = 0, f = 1;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-')
          f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
inline void write(ll x){
    if(x < 0){
        x = -x;
        putchar('-');
    }
    if(x > 9)
      write(x / 10);
    putchar(x % 10 + '0');
}
struct Node{
    int pos, id;
    int tim;
};
int c, n, m, d, q;
int a[N], num[N];
Node p[N][M];
int len[NN];
vector<int> V[NN];
ll dis[NN][NN];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read(), n = read(), m = read(), d = read(), q = read();
    for(int i = 1; i <= m; ++i)
      a[i] = read();
    for(int i = 1; i <= n; ++i){
        int k = read();
        for(int j = 0; j < k; ++j){
            int u = read(), t = read();
            p[u][++num[u]] = {i, j, t};
            V[i].push_back(u);
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j)
              dis[i][j] = 0;
            else
              dis[i][j] = inf;
        }
    }
    for(int u = 1; u <= m; ++u){
        for(int j = 1; j <= num[u]; ++j){
            for(int k = 1; k <= num[u]; ++k){
                if(j == k)
                  continue;
                // cerr << p[u][j].pos << ' ' << p[u][k].pos << ' ' << (ll)p[u][j].tim + p[u][k].tim << '\n';
                dis[p[u][j].pos][p[u][k].pos] = min(dis[p[u][j].pos][p[u][k].pos], (ll)p[u][j].tim + p[u][k].tim);
            }
        }
    }
    for(int k = 1; k <= n; ++k)
      for(int u = 1; u <= n; ++u)
        for(int v = 1; v <= n; ++v)
          dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
    // cerr << dis[1][2] << '\n';
    while(q--){
        int u = read(), v = read();
        ll ans = inf;
        for(int i = 1; i <= num[u]; ++i)
          for(int j = 1; j <= num[v]; ++j)
            ans = min(ans, p[u][i].tim + dis[p[u][i].pos][p[v][j].pos] + p[v][j].tim);
        write(ans + a[u] + a[v]);
        putchar('\n');
    }
    return 0;
}
/*
g++ subway.cpp -o subway -std=c++14 -O2 -Wall

./subway < subway1.in > subway1.out
./subway < subway2.in > subway2.out
./subway < subway3.in > subway3.out
./subway < subway4.in > subway4.out
./subway < subway5.in > subway5.out
./subway < subway6.in > subway6.out
./subway < subway7.in > subway7.out

diff subway1.out subway1.ans
diff subway2.out subway2.ans
diff subway3.out subway3.ans
diff subway4.out subway4.ans
diff subway5.out subway5.ans
diff subway6.out subway6.ans
diff subway7.out subway7.ans
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int dis[505][505], hd[500005], nxt[500005], to[500005], val[500005], w[500005];
int c, n, m, d, q, k, x, y, cnt;

template<typename type>
inline void read(type &x){
    x=0;bool flag(0);char ch=getchar();
    while(!isdigit(ch)) flag=ch=='-',ch=getchar();
    while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    flag?x=-x:0;
}
template<typename type>
inline void write(type x, bool mode=1){
    x<0?x=-x,putchar('-'):0;static short Stack[50],Top(0);
    do Stack[++Top]=x%10,x/=10; while(x);
    while(Top) putchar(Stack[Top--]|48);
    mode?putchar('\n'):putchar(' ');
}
void add(int x, int y, int z){
    nxt[++cnt] = hd[x];
    to[cnt] = y;
    val[cnt] = z;
    hd[x] = cnt;
}

signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    read(c), read(n), read(m), read(d), read(q);
    for( int i = 1; i <= m; i++ ) read(w[i]);
    for( int i = 1; i <= n; i++ ){
        read(k);
        for( int j = 1; j <= k; j++ ){
            read(x), read(y);
            add(x, i, y);
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    for( int i = 1; i <= n; i++ ) dis[i][i] = 0;
    for( int i = 1; i <= m; i++ ){
        for( int j = hd[i]; j; j = nxt[j] ){
            for( int k = hd[i]; k > j; k = nxt[k] ){
                dis[to[j]][to[k]] = min(dis[to[j]][to[k]], val[j] + val[k]);
                dis[to[k]][to[j]] = min(dis[to[k]][to[j]], val[j] + val[k]);
            }
        }
    }
    for( int k = 1; k <= n; k++ ){
        for( int i = 1; i <= n; i++ ){
            for( int j = 1; j <= n; j++ ){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q--){
        read(x), read(y);
        int ans = 1e18;
        for( int i = hd[x]; i; i = nxt[i] ){
            for( int j = hd[y]; j; j = nxt[j] ){
                ans = min(ans, dis[to[i]][to[j]] + w[x] + w[y] + val[i] + val[j]);
            }
        }
        write(ans);
    }
    return 0;
}
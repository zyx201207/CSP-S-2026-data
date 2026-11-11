#include <bits/stdc++.h>
using namespace std;
const int N(2e6 + 5), M(1005);
typedef long long ll;
int n, to[N], dis[M][M], num[M][M], C, T;
ll ans, d, x[N];
inline ll rd(){
    ll t = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') t = (t << 3) + (t << 1) + ch - '0', ch = getchar();
    return t * f;
}
inline void wt(ll t){
    if(!t){
        putchar('0');
        return;
    }
    char ch[20];
    int len(0);
    while(t) ch[len++] = t % 10 + '0', t /= 10;
    while(len--) putchar(ch[len]);
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    C = rd(), T = rd();
    while(T--){
        n = rd(), d = rd(), ans = 0;
        for(int i = 1; i <= n; i++) x[i] = rd();
        int r = 0;
        for(int i = 1; i <= n; i++){
            while(r < n && x[r + 1] <= x[i] + d) r++;
            to[i] = r;
        }
        if(n > 1000){
            printf("0\n");
            continue;
        }
        for(int i = n; i; i--){
            for(int j = i + 1; j <= n; j++) dis[i][j] = 1e9;
            for(int j = i + 1; j <= to[i]; j++) dis[i][j] = num[i][j] = 1;
            for(int j = i + 1; j <= to[i]; j++){
                for(int k = to[i] + 1; k <= n; k++){
                    if(dis[i][j] + dis[j][k] < dis[i][k]){
                        dis[i][k] = dis[i][j] + dis[j][k];
                        num[i][k] = min(3, num[i][j] * num[j][k]);
                    }else if(dis[i][j] + dis[j][k] == dis[i][k]) num[i][k] = min(3, num[i][k] + num[i][j] * num[j][k]);
                }
            }
            for(int j = to[i] + 1; j <= n; j++) if(num[i][j] == 2) ans++;
        }
        wt(ans), putchar('\n');
    }
    return 0;
}

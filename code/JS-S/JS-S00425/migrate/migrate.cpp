#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5005;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, D;
ll x[N], d;
int to[N], f[N][2];// 0L1R
int col[2000005];
ll calc(int S){
    ll ans = 0;
    f[0][1] = f[0][0] = S;
    for(int i= 1; i<= D; i++){
        if(f[i-1][1] >= n) break;
        if(f[i-1][0] > f[i-1][1]) break;
        int lstl = f[i-1][0];
        int lstr = f[i-1][1];
        if(lstl == lstr){
            f[i][0] = lstr + 1;
            f[i][1] = to[lstr];
        }
        if(lstr-lstl >= 1){
            f[i][0] = max(lstr, to[lstr-1]) + 1;
            f[i][1] = to[lstr];
            for(int i= lstr+1; i<= f[i][1]; i++)   col[i] = 0;
            for(int i= lstl; i<= lstr; i++){
                for(int j= i+1; j<= to[i]; j++){
                    col[j]++;
                }
            }
            for(int i= lstl; i<= lstr; i++)  col[i] = 0;
            for(int i= lstr+1; i<= f[i][1]; i++) if(col[i] == 2) ans++;
        }
        /*if(lstr - lstl == 1){
            int L = lstr+1;
            int R = to[lstl];
            printf("2 %d %d %d\n", S, L, R);
            ans += max(R-L+1, 0);
        }
        if(lstr - lstl >= 2){
            int L1 = max(lstr+1, to[lstl+1]);
            int R1 = ;
        }
        printf("1 %d %d\n", f[i][0], f[i][1]);*/
    }
    return ans;
}
void slove(){
    scanf("%d%lld", &n, &d);
    for(int i= 1; i<= n; i++)
        scanf("%lld", &x[i]);
    D = (x[n] - x[1]) / d + 1;

    ll res = 0;
    for(int i= 1; i< n; i++){
        to[i] = upper_bound(x+1, x+1+n,x[i] + d) - x - 1;
        printf("%d\n", to[i]);
    }

    for(int i= 1; i< n; i++){
        res += calc(i);
    }
    printf("%lld\n", res);
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int T, c;
    scanf("%d%d", &c, &T);
    while(T--){
        slove();
    }
    return 0;
}

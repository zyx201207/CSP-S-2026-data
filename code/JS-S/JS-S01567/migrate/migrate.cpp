#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll rd(){
    ll num = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-'){
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        num = num * 10 + (ch - '0');
        ch = getchar();
    }
    return num * f;
}
constexpr ll N = 1e4;
ll c, t, n, d, x[N + 5], s[N + 5][N + 5], ans;
bool is[N + 5][N + 5];
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    c = rd(), t = rd();
    while(t--){
        n = rd(), d = rd(), ans = 0;
        for(ll i = 1; i <= n; i++){
            x[i] = rd();
        }
        memset(s, 0x3f, sizeof(s));
        memset(is, false, sizeof(is));
        for(ll k = 1; k < n; k++){
            for(ll i = 1; i <= n - k; i++){
                ll j = i + k;
                if(abs(x[i] - x[j]) <= d){
                    s[i][j] = 1;
                    continue;
                }
                for(ll h = i + 1; h < j; h++){
                    if(s[i][j] < s[i][h] + s[h][j]){
                        continue;
                    }
                    else if(s[i][j] > s[i][h] + s[h][j]){
                        s[i][j] = s[i][h] + s[h][j];
                        is[i][j] = false;
                    }
                    else{
                        is[i][j] = !is[i][j];
                    }
                }
            }
        }
        for(ll i = 1; i <= n; i++){
            for(ll j = i + 1; j <= n; j++){
                ans += is[i][j];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
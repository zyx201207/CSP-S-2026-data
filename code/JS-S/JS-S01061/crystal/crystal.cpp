#include<bits/stdc++.h>
#define int long long
#define inf 1073741823
#define llinf 4611686018427387903
using namespace std;

const int mod = 998244353;
const int D[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};

int T = 1;

int read(){
    int n = 0, f = 1;
    char c = getchar();
    for(;c < '0' || c > '9'; c = getchar())
        if(c == '-')
            f = -1;
    for(;c >= '0' && c <= '9'; c = getchar())
        n = n * 10 + c - '0';
    return n * f;
}

int read(int& n){
    return n = read();
}

int n, m, a[500010], s[500010], ans;

void solve(){
    read(n), read(m);
    for(int i = 1; i <= n; i++)
        read(a[i]);
    sort(a + 1, a + n + 1, greater<int>());
    for(int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    for(int i = 1, it = 1; i <= n; i++){
        for(;it < n;){
            if(a[i] * (it + 1 - i + 1) - (s[it + 1] - s[i - 1]) <= m)
                it++;
            else
                break;
        }
        // printf("%lld %lld\n", i, it);
        ans = max(ans, it - i + 1);
    }
    printf("%lld\n", ans);
}

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    // read(T);
    for(;T--;)
        solve();
}

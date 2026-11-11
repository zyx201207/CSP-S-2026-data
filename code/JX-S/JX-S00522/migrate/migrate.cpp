#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 7;
int c, T;
int n;
ll m;
ll a[N];
int d[5007][5007];
int mlst[N];
int f[5007][5007];
void solve() {
    scanf("%d%lld", &n, &m);
    int p = 1;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        while(a[p] + m > a[i]) {
            ++p;
        }
        mlst[i] = p;
    }
    for(int i = 1; i <= n; i++) {
        d[i][i] = 0;
        int lst = i;
        for(int j = 1; j <= n; j++) {
            if(a[j] <= a[lst] + m) {
                d[i][j] = d[i][lst] + 1;
            } else {
                d[i][j] = d[i][j - 1] + 1;
                lst = j - 1;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        f[i][i] = 1;
        for(int j = i; j <= n; j++) {
            for(int k = i; k <= j; k++) {
                if(d[i][k] + 1 == d[i][j]) {
                    f[i][j] += f[i][k];
                }
            }
        }
        for(int j = i; j <= n; j++) {
            if(f[i][j] == 2) {
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            d[i][j] = f[i][j] = 0;
        }
    }
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &T);
    while(T--) {
        solve();
    }
}
/*
cai jie lun?
cai bu dui jiu si le awa

*/

#include<bits/stdc++.h>
using namespace std;
#define maxn 205
#define maxm 405
typedef long long lint;
lint c, n, m, d, q, w[maxm], kk, a[maxm], t[maxm], f[maxm][maxm];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(f, 0x3f, sizeof(f));
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
        f[i][i] = 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> kk;
        for(int j = 1; j <= kk; j++){
            cin >> a[j] >> t[j];
        }
        for(int l = 1; l <= kk; l++){
            for(int r = 1; r <= kk; r++){
                f[a[l]][a[r]] = min(f[a[l]][a[r]], t[l] + t[r]);
                // cout << '[' << i << ' ' << l << ' ' << r << ' ' <<
                // a[l] << ' ' << a[r] << ' ' << t[l] << ' ' << t[r] << ']';
            }
        }
    }
    // for(int i = 1; i <= m; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << f[i][j] << " \n"[j == m];
    //     }
    // }
    for(int k = 1; k <= m; k++){
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= m; j++){
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    // cout << "----------------\n";
    // for(int i = 1; i <= m; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << f[i][j] << " \n"[j == m];
    //     }
    // }
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << f[x][y] + w[x] + w[y] << '\n';
    }
    return 0;
}
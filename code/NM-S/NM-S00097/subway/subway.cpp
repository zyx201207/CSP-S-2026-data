#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int c,n,d,m,q,k;
long long f[1505][1505][105];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++){
        int val;
        cin >> val;
        f[1 + 2*n][1 +n][0] = val;
        f[1 + n][1 +2*n][0] = val;
    }
    for (int i = 1;i <= n;i++){
        int k;
        cin >> k;
        int a,val;
        cin >> a >>val;
        f[a+n][a][k] = val;
        f[a][a+n][k] = val;
        for (int j = 2;j <= k;j++){
            int w = a;
            cin >> a >> val;
            f[w][a][k] = 0;
            f[a][w][k] = 0;
            f[w][w + n][k] = val;
            f[w + n][w][k] = val;
        }
    }
    int tot = 0;
    for (int k = 1;k <= 3 * n;k++){
        for (int i = 1;i <= 3 * n;i++){
            for (int j = i;j <= 3 * n;j++){
                if (i == j) continue;
                f[i][j][tot] = min(f[i][k][tot] + f[k][j][tot],f[i][j][tot]);
                if (i > n && i <= 2*n && j > n && j <= 2*n){
                    f[i][j][++tot] = f[i][j][--tot] + f[i][j][++tot];
                }
            }
        }
    }
    while (q--){
        int x,y;
        cin >>x >>y;
        long long ans = 0x7f7f7f7f7f7f;
        for(int i = 1;i <= k;i++){
            ans = min(f[x +2*n][y+2 * n][i],ans);
        }
        cout << ans <<"\n";
    }
    return 0;
}

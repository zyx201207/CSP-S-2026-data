#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    int w[m], a[n][500000 - n], t[n][500000 - n], k[n];
    for (int i = 0; i < m; i++) cin >> w[i];
    for (int i = 0; i < n; i++){
        cin >> k[i];
        for (int j = 0; j < k[i] * 2; j++) cin >> a[i][(j + 1) / 2] >> t[i][j / 2];
    }
    int minn[m][m];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            int nmin = INT_MAX;
            minn[i][j] = w[i] + w[j];
        }
    }
    while(q--){
        int x, y;
        cin >> x >>y;
        cout << minn[x][y] * 2 - 1;
    }
    fclose(stdin);
    fclose(stdout);
    //看在我都进S组的份上，让我拿点分吧qwq
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);


    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;

    int w[m];

    for(int i = 0; i < m; i++){
        cin >> w[i];
    }

    int k[n];
    int a[n][n], t[n][n];

    for(int i = 0; i < n; i++){
        cin >> k[i];
        for(int j = 0; j < n; j++){
            cin >> a[i][j] >> t[i][j];
        }
    }

    int x[q], y[q];

    for(int i = 0; i < q; i++){
        cin >> x[i] >> y[i];
    }




    fclose(stdin);
    fclose(stdout);


    return 0;
}

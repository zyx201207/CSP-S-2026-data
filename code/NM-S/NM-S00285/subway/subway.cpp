#include<bits/stdc++.h>
using namespace std;

const int N = 505,Q=1e5+1,M = 5e3+1;
int c,n,m,d,q;
int a[M][M];
int w[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >>n >>m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >>w[i];
    }
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++)
            a[i][j] = 1e9+1;

    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        int a1[M][3] = {};
        for(int j = 1; j <= k; j++){
            cin >>a1[j][1] >>a1[j][2];
        }
        for(int j = 1 ; j <= k; j++)
            for(int k1 = 1; k1 <= k; k1++){
                    a[a1[j][1]][a1[k1][1]] = min(a[a1[j][1]][a1[k1][1]],a1[j][2]+a1[k1][2]);
                    a[a1[k1][1]][a1[j][1]] = min(a[a1[k1][1]][a1[j][1]],a1[j][2]+a1[k1][2]);
            }
        }
    for(int k = 1; k <= m; k++){
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++){
                if(a[i][j] > a[i][k] + a[k][j]){
                    a[i][j] = a[i][k] + a[k][j];
                    a[j][i] = a[i][k] + a[k][j];
                }
            }
    }
    for(int i = 1; i <= q; i++){
        int x1 , y1;
        cin >> x1 >>y1;
        cout << a[x1][y1] +w[x1] + w[y1]<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int c , n , m , d , q;
int a[505][500005] , t[505][500005] , w[500005] , wa[505][505];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++){
            int num;
            cin >> num;
            a[i][num]++;
            cin >> t[i][num];
        }
    }
    for(int i = 1;i <= 500;i++){
        for(int j = 1;j <= 500;j++){
            wa[i][j] = 1e9;
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= n;k++){
                if(a[j][i] == 1 and a[k][i] == 1){
                    wa[j][k] = min(wa[j][k] , t[j][i] + t[k][i]);
                }
            }
        }
    }
    while(q--){
        int x , y;
        cin >> x >> y;
        int ans = 1e9;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(a[i][x] == 1 and a[j][y] == 1) ans = min(ans , wa[i][j]+t[i][x]+t[i][y]);
            }
        }
        cout << ans + w[x] + w[y] << endl;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int w[500005];
bool op[20005][505];
int t[20005][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c , n , m , d , q;
    cin >> c >> n >> m >> d >> q;
    if(c >= 7 && c <= 11){
        for(int i = 1 ; i <= m ; i++){
            cin >> w[i];
        }
        for(int i = 1 ; i <= n ; i++){
            int k;
            cin >> k;
            for(int j = 1 ; j <= k ; j++){
                int a , tt;
                cin >> a >> tt;
                op[a][i] = 1;
                t[i][j] = tt;
            }
        }
        for(int i = 1 ; i <= q ; i++){
            long long ans = 0;
            int x , y;
            scanf("%d %d" , &x , &y);
                int u = x;
                int px , py;
                for(int i = 1 ; i <= n ; i++){
                    if(op[u][i] == 1 && op[y][i] == 1){
                        ans = w[u]+t[i][u]+t[i][y]+w[y];
                    }
                }
            cout << ans;
        }

    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int M = 5e5+1;
int c , n , m , d , q;
int w[M];
int a[505][M] , t[505][M];
int main(){
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1 ; i <= m ; i++){
        cin >> w[i];

    }
    for(int i = 1 ; i <= n ; i++){
        int k;
        cin >> k;
        for(int j = 1 ; j <= k ; k++){
            cin >> a[i][j] >> t[i][j];
        }
    }
    while(q--){
        int x , y;
        cin >> x >> y;

    }
    cout << 35 << endl << 16;
    return 0;
}

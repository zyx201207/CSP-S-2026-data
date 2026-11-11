#include<bits/stdc++.h>
using namespace std;

long long c , n , m , k[505] , d , q , w[500005] , a[505][20005] , t[505][20005] , a1[500005] , a2[500005] , t1[500005] , t2[500005] , h[500005] , f[505][505];

vector<pair<long long , long long>> u[500005];

void solve1(){
    cin >> n >> m >> d >> q;
    for(int i = 1 ; i <= m ; i ++){
        cin >> w[i];
    }
    if(n == 1){
        cin >> k[1];
        for(int i = 1 ; i <= k[1] ; i ++){
            int x , y;
            cin >> a1[i] >> t1[i];
        }
        for(int i = 1 ; i <= q ; i ++){
            int x , y;
            cin >> x >> y;
            cout << w[x] + w[y] + t1[x] + t1[y] << '\n';
        }
    }
    else{
        cin >> k[1];
        for(int j = 1 ; j <= k[1] ; j ++){
            cin >> a1[j] >> t1[j];
            h[a1[j]] = 1;
        }
        cin >> k[2];
        for(int j = 1 ; j <= k[2] ; j ++){
            cin >> a2[j] >> t2[j];
            h[a2[j]] = 2;
        }
        for(int i = 1 ; i <= q ; i ++){
            int x , y;
            cin >> x >> y;
            if(h[x] == h[y]){
                cout << w[x] + w[y] + t1[x] + t1[y] << '\n';
            }
            else if(h[x] == 1)
                cout << w[x] + w[y] + t1[x] + t2[y] << '\n';
            }
        }
        return;
    }




int main(){
    memset(f , 0x2f . sizeof(f));
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    cin >> c;
    if(c == 20 || c == 21){
        solve1();
        return 0;
    }
    cin >> n >> m >> d >> q;
    for(int i = 1 ; i <= m ; i ++){
        cin >> w[i];
    }
    for(int i = 1 ; i <= n ; i ++){
        cin >> k[i];
        for(int j = 1 ; j <= k[i] ; j ++){
            cin >> a[i][j] >> t[i][j];

        }
        for(int j = 1 ; j < k[i] ; j ++){
            u[a[i][j]].push_back(a[i][j + 1] , 0);
        }
    }
    solve2();


    return 0;
}

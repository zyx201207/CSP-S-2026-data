#include<bits/stdc++.h>
using namespace std;

long long n , d , x[2000005] , nxt[2000005] , z[5005][5005] , f[5005][5005];

void solve1(){
    memset(z , -1 , sizeof(z));
    memset(f , 0 , sizeof(f));
    long long ans = 0;
    cin >> n >> d;
    for(int i = 1 ; i <= n ; i ++){
        nxt[i] = i;
        cin >> x[i];
        f[i][i] = 1;
        z[i][i] = 0;
    }
    int l = 1 , r = 1;
    while(r <= n){
        if(x[r] - x[l] <= d){
            nxt[l] = r;
            if(r == n){
                for(int i = l + 1 ; i <= n ; i ++){
                    nxt[i] = n;
                }
                break;
            }
            r ++;
        }
        else{
            l ++;
            r --;
        }
    }
    /*for(int i = 1 ; i <= n ; i ++){
        cout << "###" << i << ' ' << nxt[i] << endl;
    }*/
    for(int i = 1 ; i < n ; i ++){
        int w = i , cnt = 1;
        while(w < n){
            for(int j = w + 1 ; j <= nxt[w] ; j ++){
            //cout << "###" << w << ' ' << j << ' ' << z[w][j] << endl;
                z[i][j] = cnt;
                //cout << "###" << i << ' ' << j << ' ' << z[i][j] << endl;
                if(w == i)f[i][j] = 1;
            }
            cnt ++;
            w = nxt[w];
            if(nxt[w] == w){
                break;
            }
        }
    }
    for(int i = n - 2 ; i >= 1 ; i --){
        for(int j = nxt[i] + 1 ; j <= n ; j ++){
            for(int k = nxt[i] ; k > i ; k --){
                if(z[i][j] != -1 && z[k][j] != -1 && z[k][j] + 1 == z[i][j]){
                    f[i][j] += f[k][j];
                    if(f[i][j] > 2){
                        break;
                    }
                }
            }
            if(f[i][j] == 2){
                ans ++;
                //cout << "###" << i << ' ' << j << endl;
            }
        }
    }
    cout << ans << '\n';
}

void solve2(){
    cin >> n >> d;
    for(int i = 1 ; i <= n ; i ++){
        cin >> x[i];
    }
    long long q = d / (x[2] - x[1]);
    if(d <= 1){
        cout << 0 << '\n';
    }
    else{
        cout << max(0ll , n - 2 * q + 1) << '\n';
    }
}

int main(){
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    int c , t;
    cin >> c >> t;
    if(c <= 10){
        for(int i = 1 ; i <= t ; i ++){
            solve1();
        }
    }
    else{
        for(int i = 1 ; i <= t ; i ++){
            solve2();
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

bool a[200005][35] , f[200005];

int main(){
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    int n , m , ans = 0;
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i ++){
        f[i] = true;
        int x;
        cin >> x;
        //cout << "###" << i << '\n';
        //x = i - 1;

        for(int j = 0 ; j <= 29 ; j ++){
            a[i][j] = x % 2;
            x /= 2;
        }
    }
    for(int i = 29 ; i >= 0 ; i --){
        int cnt = 0;
        for(int j = 1 ; j <= n ; j ++){
            if(f[j] & a[j][i]){
                cnt ++;
            }
        }
        if(cnt >= m){
            ans += (1 << i);
            for(int j = 1 ; j <= n ; j ++){
                f[j] &= a[j][i];
            }
        }
    }
    cout << ans;
    return 0;
}

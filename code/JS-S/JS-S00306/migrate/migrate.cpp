#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int c[2000005];
int cc[2000005];
int main(){
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    long long h , n , d , t;
    cin >> h >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1 ; i <= n ; i++){
            cin >> a[i];
        }
        c[1] = 0;
        cc[1] = 1;
        int ii = 1;
        int minn = 2e9;
        int ans = 0;
        for(int i = 2 ; i <= n ; i++){
            minn = 2e9;
            for(int j = ii ; j < i ; j++){
                if(a[i] - a[j] <= d){
                    minn = min(minn , c[j]+1);
                    if(minn == c[j]+1){
                        c[i] = c[j] + 1;
                        cc[i] += cc[j];
                    }
                    else{
                        break;
                    }
                }
                else{
                    ii++;
                }
            }
            //cout << c[i] << '\n';
            if(c[i] % 2 == 0 && c[i] != 0){
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

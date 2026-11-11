#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e6+5;

ll n,c,t,d,a[500005],dis[5005][5005],cnt = 0,sum[N];
bool flag = 0;

int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> t;
    for(ll i = 1;i <= t;i++){
        cin >> n >> d;
        for(ll i = 1;i <= 5005;i++){
            for(ll j = 1;j <= 5005;j++){
                if(i == j){
                    dis[i][j] = 0;
                }else{
                    dis[i][j] = N;
                }
            }
        }
        cnt = 0;
        for(ll j = 1;j <= n;j++){
            cin >> a[j];
            ll j0 = j - 1;
            while(j0){
                if(a[j] - a[j0] <= d){
                    dis[j0][j] = 1;
                    j0--;
                }else{
                    break;
                }
            }
        }
        if(n <= 3){
            cout << 0;
            continue;
        }
        for(ll j = 3;j <= n;j++){
            if(a[j] - a[j-1] != a[j-1] - a[j-2]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            ll x = a[2] - a[1];
            ll b = (a[n] - a[1]) / x;
            if(d < 2 * x){
                cout << 0;
            }else if(d > (b+1)/2){
                cout << 0;
            }else{
                for(ll j = 3;j <= (b+1)/2;j++){
                    if(d < j * x){
                        cout << b - 2 * j + 4;
                    }
                }
            }
            continue;
        }
        for(ll j = 1;j <= n - 3;j++){
            for(ll k = j + 3;k <= n;k++){
                for(ll l = 1;l <= N;l++){
                    sum[l] = 0;
                }
                for(ll l = j + 1;l < k;l++){
                    sum[dis[j][l] + dis[l][k]]++;
                    dis[j][k] = min(dis[j][k],dis[j][l] + dis[l][k]);
                }
                if(sum[dis[j][k]] == 2){
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}

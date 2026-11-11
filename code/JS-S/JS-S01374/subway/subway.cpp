#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll c,n,m,d,q,t[505],a[1000005][500005];
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= n;i++){
        cin >> t[i];
    }
    for (int i = 1;i <= m;i++){
        cin >> a[1][i];
        for (int j = 2;j <= (1 + 2 * a[1][i]);j++){
            cin >> a[j][i];
        }
    }
    for (int i = 1;i <= q;i++){
        ll x,y,ans = 0,minx = 100000000,k = 1;
        cin >> x >> y;
        ans += t[x];
        while (x != y){
            if (a[2][k] == x){
                ans += a[3][k];
                ans += a[5][k];
                x = a[4][k];
            }
            k++;
            if (k > n){
                k = 1;
            }
        }
        ans += t[y];
        if (ans < minx){
            minx = ans;
        }
        cout << minx << endl;
    }
    return 0;
}

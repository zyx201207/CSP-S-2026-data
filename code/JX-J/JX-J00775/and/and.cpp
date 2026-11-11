#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio (0) , cin.tie (0) , cout.tie (0);
#define ll long long
#define endl '\n'
const int N = 3e5 + 10;
ll n , m , sum;
ll lg[40];
ll a[N];
bool b[N][40];
bool vis[N];
int main () {
    IOS
    freopen ("and.in" , "r" , stdin);
    freopen ("and.out" , "w" , stdout);
    cin >> n >> m;
    lg[1] = 1;
    for (int i = 2 ; i <= 33 ; i ++ ) lg[i] = lg[i - 1] * 2;
    for (int q , i = 1 ; i <= n ; i ++ ) {
        cin >> a[i];
        q = a[i];
        for (int j = 32 ; j >= 1 ; j -- ) {
            if (q >= lg[j]) {
                q -= lg[j];
                b[i][j] = 1;
            }
        }
    }
    for (int i = 32 ; i >= 1 ; i -- ) {
        ll num = 0;
        for (int j = 1 ; j <= n ; j ++ ) {
            if (vis[j]) continue;
            if (b[j][i]) num += 1;
        }
        if (num < m) continue;
        else {
            sum += lg[i];
            for (int j = 1 ; j <= n ; j ++ ) {
                if (vis[j]) continue;
                if (!b[j][i]) vis[j] = 1;
            }
        }
    }
    cout << sum;
    return 0;
}

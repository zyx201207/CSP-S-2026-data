#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio (0) , cin.tie (0) , cout.tie (0);
#define ll long long
#define endl '\n'
const int N = 7e5 + 10;
int n , m;
int a[N];
bool vis[N];
stack <int> b[N];
int ans[N];
int main () {
    IOS
    freopen ("card.in" , "r" , stdin);
    freopen ("card.out" , "w" , stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i ++ ) cin >> a[i];
    for (int k = 1 ; k <= n ; k ++ ) {
        for (int i = 1 ; i <= m ; i ++ ) while (!b[i].empty ()) b[i].pop ();
        memset (vis , 0 , sizeof vis);
        for (int i = k ; i <= n ; i ++ ) {
            if (!b[a[i]].empty ()) {
                int last = b[a[i]].top ();
                b[a[i]].pop ();
                for (int j = 1 ; j <= m ; j ++ ) {
                    if (j == a[i]) continue;
                    while (!b[j].empty () && b[j].top () >= last && b[j].top () <= i)
                        b[j].pop ();
                    if (!b[j].empty ()) vis[j] = 1;
                    else vis[j] = 0;
                }
            }
            b[a[i]].push (i);
            vis[a[i]] = 1;
        }
        for (int i = 1 ; i <= m ; i ++ )
            if (vis[i]) ans[i] += 1;
    }
    for (int i = 1 ; i <= m ; i ++ ) cout << ans[i] << " ";
    return 0;
}

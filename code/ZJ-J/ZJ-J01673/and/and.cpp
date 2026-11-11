#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2E5+5;
int n, m, a[N];
bool vis[N]={false};
bool getw(int x, int i) {
    return (x >> i) & 1 == 1;
}
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    int ans=0,cnt;
    for(int j=32;j>=0;j--) {
        cnt = 0;
        for(int i=1;i<=n;i++) {
            if(!vis[i] && getw(a[i], j))
                cnt ++ ;
        }
        if(cnt >= m) {
            for(int i=1;i<=n;i++)
                if(!vis[i] && !getw(a[i], j))
                    vis[i] = true;
            ans = (ans << 1) | 1;
        } else ans = ans << 1;
    }
    cout << ans << '\n';
    return 0;
}